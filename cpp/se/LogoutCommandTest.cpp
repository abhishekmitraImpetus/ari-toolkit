#include "common/init.hpp"
#include "common/Test.hpp"
#include "se/CLTRID.hpp"
#include "se/LogoutCommand.hpp"
#include "session/Timer.hpp"

#include <iostream>

using namespace std;

void doWork()
{
	init("etc/toolkit2.conf");
	{
		CLTRID::setClID("JTKUTEST");
		Timer::setTime("20070101.010101");

		LogoutCommand cmd;

		const string xml(cmd.toXML());
		ASSERT_EQ(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?><epp xmlns=\"urn:ietf:params:xml:ns:epp-1.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"urn:ietf:params:xml:ns:epp-1.0 epp-1.0.xsd\"><command><logout/><clTRID>JTKUTEST.20070101.010101.0</clTRID></command></epp>");
	}
}

int main(int argc, char* argv[])
{
	TEST_run(doWork);
	return TEST_errorCount();
}