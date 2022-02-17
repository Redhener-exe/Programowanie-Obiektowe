#pragma once

#include <memory>

class Komenda {
public:
    virtual void wykonaj() = 0;
};

using pcommand = std::shared_ptr<Komenda>;
