#include "common/init.hpp"
#include "common/Test.hpp"
#include "se/CLTRID.hpp"
#include "se/HostCheckCommand.hpp"
#include "session/Timer.hpp"

#include <iostream>

using namespace std;

void doWork()
{
	init("etc/toolkit2.conf");
	{
		CLTRID::setClID("JTKUTEST");
		Timer::setTime("20070101.010101");
		HostCheckCommand hcc("ns1.jtkutest.com.au");
		const string xml(hcc.toXML());
		ASSERT_EQ(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?><epp xmlns=\"urn:ietf:params:xml:ns:epp-1.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"urn:ietf:params:xml:ns:epp-1.0 epp-1.0.xsd\"><command><check><check xmlns=\"urn:ietf:params:xml:ns:host-1.0\" xsi:schemaLocation=\"urn:ietf:params:xml:ns:host-1.0 host-1.0.xsd\"><name>ns1.jtkutest.com.au</name></check></check><clTRID>JTKUTEST.20070101.010101.0</clTRID></command></epp>");
	}

	{
		CLTRID::setClID("JTKUTEST");
		Timer::setTime("20070101.010101");
		std::vector<std::string> names;
		names.push_back("ns1.jtkutest.com.au");
		names.push_back("ns2.jtkutest.com.au");

		HostCheckCommand hcc(names);
		const string xml(hcc.toXML());
		ASSERT_EQ(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?><epp xmlns=\"urn:ietf:params:xml:ns:epp-1.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"urn:ietf:params:xml:ns:epp-1.0 epp-1.0.xsd\"><command><check><check xmlns=\"urn:ietf:params:xml:ns:host-1.0\" xsi:schemaLocation=\"urn:ietf:params:xml:ns:host-1.0 host-1.0.xsd\"><name>ns1.jtkutest.com.au</name><name>ns2.jtkutest.com.au</name></check></check><clTRID>JTKUTEST.20070101.010101.0</clTRID></command></epp>");
	}

}

int main(int argc, char* argv[])
{
	TEST_run(doWork);
	return TEST_errorCount();
}