/*
 * Need Improve:
 * 	1. use boost::posix_time instead of time(NULL)
 * Next Step:
 * 	1. add tracer
 * 	2. do experiment
 * 	3. implement ChronoSync
 */

// #include "drs-app.h"
#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"

#include "ns3/ndn-app-face.h"
#include "ns3/ndn-interest.h"
#include "ns3/ndn-data.h"

#include "ns3/ndn-fib.h"
#include "ns3/random-variable.h"
#include "ns3/core-module.h"
// #include "../hebi.h"
#include<boost/foreach.hpp>

#include "stream.h"

NS_LOG_COMPONENT_DEFINE("Stream");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED(Stream);


TypeId Stream::GetTypeId()
{
	static TypeId tid = TypeId("Stream")
		.SetParent<ndn::App>()
		.AddConstructor<Stream>()
		;
	return tid;
}

void Stream::StartApplication()
{
	NS_LOG_DEBUG(Simulator::Now().GetSeconds());
	ndn::App::StartApplication();
}

void Stream::StopApplication()
{
	ndn::App::StopApplication();
}

void Stream::OnInterest(Ptr<const ndn::Interest> interest)
{
	NS_LOG_DEBUG("Received Interest: "<<interest->GetName());
	ndn::App::OnInterest(interest);
}
void Stream::OnData(Ptr<const ndn::Data> contentObject)
{
	NS_LOG_DEBUG("Received Data for: "<<contentObject->GetName());
}


/*===================================================================================
 * 				Stable Functions
 *==================================================================================*/
// void Stream::SendData(const std::string &name, const std::string &msg)
// {
// 	const ndn::Name _name(name);
// 	SendData(_name, msg);
// }
// void Stream::SendData(const ndn::Name &name, const std::string &msg)
// {
// 	NS_LOG_DEBUG("Send Data for: "<<name);
// 	Ptr<Packet> packet = Create<Packet>(msg);
// 	Ptr<ndn::Data> data = Create<ndn::Data>(packet);
// 	data->SetName(name);
// 	m_transmittedDatas(data, this, m_face);
// 	m_face->ReceiveData(data);
// }
// void Stream::SendInterest(const std::string &name)
// {
// 	const ndn::Name _name(name);
// 	SendInterest(_name);
// }
// void Stream::SendInterest(const ndn::Name &name)
// {
// 	NS_LOG_DEBUG("Send Interest for: "<<name);
// 	Ptr<ndn::Interest> interest = Create<ndn::Interest>();
// 	UniformVariable rand(0, std::numeric_limits<uint32_t>::max());
// 	interest->SetNonce(rand.GetValue());
// 	interest->SetName(name);
// 	interest->SetInterestLifetime(Seconds(m_env_ILT)); //????
// 	m_transmittedInterests(interest, this, m_face);
// 	m_face->ReceiveInterest(interest);
// }



} //ns3
