// #ifndef _CHATAPP_H_
// #define _CHATAPP_H_
#include "ns3/ndn-app.h"

#include "ns3/ndn-app-face.h"
#include "ns3/random-variable.h"

namespace ns3 {

class Stream : public ndn::App
{
public:
	static TypeId GetTypeId();
	void StartApplication();
	void StopApplication();
	void OnInterest(Ptr<const ndn::Interest> interest);
	void OnData(Ptr<const ndn::Data> contentObject);
};

} //end namespace ns3

// #endif
