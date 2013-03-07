#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include "Parser.hpp"

using namespace xercesc;
using namespace std;

/**
 *  Constructor initializes xerces-C libraries.
 *  The XML tags and attributes which we seek are defined.
 *  The xerces-C DOM parser infrastructure is initialized.
 */

GetConfig::GetConfig() {
	try {
		XMLPlatformUtils::Initialize();  // Initialize Xerces infrastructure
	} catch (XMLException& e) {
		char* message = XMLString::transcode(e.getMessage());
		cerr << "XML toolkit initialization error: " << message << endl;
		XMLString::release(&message);
		// throw exception here to return ERROR_XERCES_INIT
	}

	// Tags and attributes used in XML file.
	// Can't call transcode till after Xerces Initialize()
	TAG_root = XMLString::transcode("root");
	TAG_Player = XMLString::transcode("Player");
	ATTR_Score = XMLString::transcode("Score");
	ATTR_HighSpeed = XMLString::transcode("HighSpeed");
	ATTR_HighTraction = XMLString::transcode("HighTraction");
	ATTR_HighTrack = XMLString::transcode("HighTrack");
	ATTR_MediumTrack = XMLString::transcode("MediumTrack");
	ATTR_Invincible = XMLString::transcode("Invincible");

	m_ConfigFileParser = new XercesDOMParser;
}

/**
 *  Class destructor frees memory used to hold the XML tag and
 *  attribute definitions. It als terminates use of the xerces-C
 *  framework.
 */

GetConfig::~GetConfig() {
	// Free memory

	delete m_ConfigFileParser;
	if (m_Score)
		XMLString::release(&m_Score);
	if (m_HighSpeed)
		XMLString::release(&m_HighSpeed);

	try {
		XMLString::release(&TAG_root);
		XMLString::release(&TAG_Player);
		XMLString::release(&ATTR_Score);
		XMLString::release(&ATTR_HighSpeed);
		XMLString::release(&ATTR_HighTraction);
		XMLString::release(&ATTR_HighTrack);
		XMLString::release(&ATTR_MediumTrack);
		XMLString::release(&ATTR_Invincible);
	} catch (...) {
		cerr << "Unknown exception encountered in TagNamesdtor" << endl;
	}

	// Terminate Xerces

	try {
		XMLPlatformUtils::Terminate();  // Terminate after release of memory
	} catch (xercesc::XMLException& e) {
		char* message = xercesc::XMLString::transcode(e.getMessage());

		cerr << "XML ttolkit teardown error: " << message << endl;
		XMLString::release(&message);
	}
}

/**
 *  This function:
 *  - Tests the access and availability of the XML configuration file.
 *  - Configures the xerces-c DOM parser.
 *  - Reads and extracts the pertinent information from the XML config file.
 *
 *  @param in configFile The text string name of the HLA configuration file.
 */

void GetConfig::readConfigFile(string& configFile) throw (std::runtime_error) {
	// Test to see if the file is ok.

	struct stat fileStatus;

	int iretStat = stat(configFile.c_str(), &fileStatus);
	if (iretStat == ENOENT)
		throw(std::runtime_error(
				"Path file_name does not exist, or path is an empty string."));
	else if (iretStat == ENOTDIR)
		throw(std::runtime_error("A component of the path is not a directory."));
	else if (iretStat == ELOOP)
		throw(std::runtime_error(
				"Too many symbolic links encountered while traversing the path."));
	else if (iretStat == EACCES)
		throw(std::runtime_error("Permission denied."));
	else if (iretStat == ENAMETOOLONG)
		throw(std::runtime_error("File can not be read\n"));

	// Configure DOM parser.

	m_ConfigFileParser->setValidationScheme(XercesDOMParser::Val_Never);
	m_ConfigFileParser->setDoNamespaces(false);
	m_ConfigFileParser->setDoSchema(false);
	m_ConfigFileParser->setLoadExternalDTD(false);

	try {
		m_ConfigFileParser->parse(configFile.c_str());

		// no need to free this pointer - owned by the parent parser object
		DOMDocument* xmlDoc = m_ConfigFileParser->getDocument();

		// Get the top-level element: NAme is "root". No attributes for "root"

		DOMElement* elementRoot = xmlDoc->getDocumentElement();
		if (!elementRoot)
			throw(std::runtime_error("empty XML document"));

		// Parse XML file for tags of interest: "ApplicationSettings"
		// Look one level nested within "root". (child of root)

		DOMNodeList* children = elementRoot->getChildNodes();
		const XMLSize_t nodeCount = children->getLength();

		// For all nodes, children of "root" in the XML tree.

		for (XMLSize_t i = 0; i < nodeCount; ++i) {
			DOMNode* currentNode = children->item(i);
			if (currentNode->getNodeType() &&  // true is not NULL
					currentNode->getNodeType() == DOMNode::ELEMENT_NODE) // is element
							{
				DOMElement* currentElement =
						dynamic_cast<xercesc::DOMElement*>(currentNode);
				if (XMLString::equals(currentElement->getTagName(),
						TAG_Player)) {

					const XMLCh* xmlch_Score = currentElement->getAttribute(
							ATTR_Score);
					m_Score = XMLString::transcode(xmlch_Score);

					const XMLCh* xmlch_HighSpeed = currentElement->getAttribute(
							ATTR_HighSpeed);
					m_HighSpeed = XMLString::transcode(xmlch_HighSpeed);

					const XMLCh* xmlch_HighTraction =
							currentElement->getAttribute(ATTR_HighTraction);
					m_HighTraction = XMLString::transcode(xmlch_HighTraction);

					const XMLCh* xmlch_HighTrack = currentElement->getAttribute(
							ATTR_HighTrack);
					m_HighTrack = XMLString::transcode(xmlch_HighTrack);

					const XMLCh* xmlch_MediumTrack =
							currentElement->getAttribute(ATTR_MediumTrack);
					m_MediumTrack = XMLString::transcode(xmlch_MediumTrack);

					const XMLCh* xmlch_Invicible = currentElement->getAttribute(
							ATTR_Invincible);
					m_Invincible = XMLString::transcode(xmlch_Invicible);

					break; // Data found. No need to look at other elements in tree.
				}
			}
		}
	} catch (xercesc::XMLException& e) {
		char* message = xercesc::XMLString::transcode(e.getMessage());
		ostringstream errBuf;
		errBuf << "Error parsing file: " << message << flush;
		XMLString::release(&message);
	}
}

