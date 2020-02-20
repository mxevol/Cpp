#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    using namespace log4cpp;
    Category & root = Category::getRoot();
    OstreamAppender *pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    pOstreamAppender->setLayout(new BasicLayout());

    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::DEBUG);

    root.debug("this is a debug message");

    Category::shutdown();
    return 0;
}

