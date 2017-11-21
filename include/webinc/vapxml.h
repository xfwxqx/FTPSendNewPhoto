//
// suntek-video
// filename: vapxml.h
// designer: Arora.chen
// date:		2008-5-9
//

#ifndef _VAP_XML_H__
#define _VAP_XML_H__

typedef unsigned int VAP_WEB_HANDLE;

typedef enum _WEBS_VAPREQ_TYPE_E
{
	TYPE_WEBSVAPREQ_GET,
	TYPE_WEBSVAPREQ_POST,
	
	TYPE_WEBSVAPREQ_BUTT = 0xff
}WEBS_VAPREQ_TYPE;

typedef int (*websvapRequestCallback)(VAP_WEB_HANDLE wpHandle,WEBS_VAPREQ_TYPE reqType,void *pContext);

#endif //_VAP_XML_H__

