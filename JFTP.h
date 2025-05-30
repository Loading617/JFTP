#ifndef _JFTP_JFTP_h
#define _JFTP_JFTP_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <JFTP/JFTP.lay>
#include <CtrlCore/lay.h>

class JFTP : public WithJFTPLayout<TopWindow> {
public:
	JFTP();
};

#endif
