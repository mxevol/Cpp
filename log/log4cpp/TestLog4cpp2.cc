#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

int main()
{
    Category & myRecord = Category::getRoot();
    PatternLayout *patternLayout = new PatternLayout();
    patternLayout->setConversionPattern("%d [%p] %m%n");

    OstreamAppender* ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(patternLayout);

    myRecord.setAppender(ostreamAppender);
    myRecord.setPriority(Priority::ERROR);

    myRecord.emerg("This is a emerg message");
    myRecord.fatal("This is fatal message");
    myRecord.alert("This is alert  message");
    myRecord.crit("This is a crit message");
    myRecord.warn("This is a warn message");
    myRecord.error("This is a error message");
    myRecord.notice("This is a notice message");
    myRecord.info("This is a info message");
    myRecord.debug("This is a debug message");

    Category::shutdown();
    return 0;
}

