#include "cyber/common/log.h"
/**
 * Copyright (c) 2019 LG Electronics, Inc.
 *
 * This software contains code licensed as described in LICENSE.
 *
 */
#include "modules/contrib/cyber_bridge/clients.h"

#include <memory>

#include "modules/contrib/cyber_bridge/client.h"

Clients::Clients() {}

Clients::~Clients() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

void Clients::start(std::shared_ptr<Client> client) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  clients.insert(client);
  client->start();
}

void Clients::stop(std::shared_ptr<Client> client) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  clients.erase(client);
  client->stop();
}

void Clients::stop_all() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  for (auto& client : clients) {
    client->stop();
  }
  clients.clear();
}
