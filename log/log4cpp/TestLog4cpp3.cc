#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

int main()
{
    Category & myRecord = Category::getRoot();
    PatternLayout * patternLayout1 = new PatternLayout();
    patternLayout1->setConversionPattern("%d [%p] %m%n");
    PatternLayout * patternLayout2 = new PatternLayout();
    patternLayout2->setConversionPattern("%d [%p] %m%n");
    PatternLayout * patternLayout3 = new PatternLayout();
    patternLayout3->setConversionPattern("%d [%p] %m%n");

    OstreamAppender * ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(patternLayout1);

    FileAppender * fileAppender = new FileAppender("FileAppender", "wangdao.log");
    fileAppender->setLayout(patternLayout2);

    RollingFileAppender * rollingFileAppender = new RollingFileAppender(
        "rollingFileAppender",
        "rollingwangdao.log",
        1024,
        10);
    rollingFileAppender->setLayout(patternLayout3);

    myRecord.setAppender(ostreamAppender);
    myRecord.addAppender(fileAppender);
    myRecord.addAppender(rollingFileAppender);

    myRecord.setPriority(Priority::DEBUG);

    for(int idx = 0; idx != 50; ++idx){
        myRecord.emerg("This is a emerg message");
        myRecord.fatal("This is fatal message");
        myRecord.alert("This is alert  message");
        myRecord.crit("This is a crit message");
        myRecord.warn("This is a warn message");
        myRecord.error("This is a error message");
        myRecord.notice("This is a notice message");
        myRecord.info("This is a info message");
        myRecord.debug("This is a debug message");
    }
    Category::shutdown();
    return 0;
}

