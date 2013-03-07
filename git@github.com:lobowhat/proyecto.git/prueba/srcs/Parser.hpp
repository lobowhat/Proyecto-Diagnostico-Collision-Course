#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP


#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>

#include <string>
#include <stdexcept>

// Error codes

enum {
	ERROR_ARGS = 1, ERROR_XERCES_INIT, ERROR_PARSE, ERROR_EMPTY_DOCUMENT
};

class GetConfig {
public:
	GetConfig();
	~GetConfig();
	void readConfigFile(std::string&) throw (std::runtime_error);

	char *getScore() {
		return m_Score;
	}
	char *getHighSpeed() {
		return m_HighSpeed;
	}
	char *getHighTraction() {
		return m_HighTraction;
	}
	char *getHighTrack() {
		return m_HighTrack;
	}
	char *getMediumTrack() {
		return m_MediumTrack;
	}
	char *getInvincible() {
		return m_Invincible;
	}

private:
	xercesc::XercesDOMParser *m_ConfigFileParser;
	char* m_Score;
	char* m_HighSpeed;
	char* m_HighTraction;
	char* m_HighTrack;
	char* m_MediumTrack;
	char* m_Invincible;

	// Internal class use only. Hold Xerces data in UTF-16 SMLCh type.

	XMLCh* TAG_root;

	XMLCh* TAG_Player;
	XMLCh* ATTR_Score;
	XMLCh* ATTR_HighSpeed;
	XMLCh* ATTR_HighTraction;
	XMLCh* ATTR_HighTrack;
	XMLCh* ATTR_MediumTrack;
	XMLCh* ATTR_Invincible;
};
#endif
