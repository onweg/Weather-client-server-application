#ifndef SHAREDSTATE_H
#define SHAREDSTATE_H

#include "../../../domain/interfaces/sharedstate/ISharedState.h"

class SharedState : public ISharedState
{
  public:
	SharedState();
	std::string getUsername() override;
	void setUsername(const std::string &username) override;

  private:
	std::string username_ = "";
};

#endif // SHAREDSTATE_H
