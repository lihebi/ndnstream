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

#include "stream-router.h"

NS_LOG_COMPONENT_DEFINE("StreamRouter");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED(StreamRouter);


TypeId StreamRouter::GetTypeId()
{
  static TypeId tid = TypeId("StreamRouter")
    .SetParent<ndn::App>()
    .AddConstructor<StreamRouter>()
    ;
  return tid;
}

void StreamRouter::StartApplication()
{
  NS_LOG_DEBUG(Simulator::Now().GetSeconds());
  ndn::App::StartApplication();
}

void StreamRouter::StopApplication()
{
  ndn::App::StopApplication();
}

void StreamRouter::OnInterest(Ptr<const ndn::Interest> interest)
{
  NS_LOG_DEBUG("Received Interest: "<<interest->GetName());
  ndn::App::OnInterest(interest);
}
void StreamRouter::OnData(Ptr<const ndn::Data> contentObject)
{
  NS_LOG_DEBUG("Received Data for: "<<contentObject->GetName());
}




} //ns3
