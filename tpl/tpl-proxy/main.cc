#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <any>

struct ITransport
{
    virtual ~ITransport() = default;
    
    virtual void WhoAmI() const = 0;
    
    virtual int GetMaxSpeed() const = 0;
    virtual void SetMaxSpeed(int maxSpeed) = 0;
};

class Car : public ITransport
{
public:
    Car()
        : maxSpeed_(0)
    {}
        
    ~Car() override = default;
    
    void WhoAmI() const override
    {
        std::cout << "Car" << std::endl;
    }

    int GetMaxSpeed() const override
    {
        return maxSpeed_;
    }
    
    void SetMaxSpeed(int maxSpeed) override
    {
        maxSpeed_ = maxSpeed;
    }

private:
    int maxSpeed_;
};

class Airplane : public ITransport
{
public:
    Airplane()
        : maxSpeed_(0)
    {}

    ~Airplane() override = default;
    
    void WhoAmI() const override
    {
        std::cout << "Airplane" << std::endl;
    }
    
    int GetMaxSpeed() const override
    {
        return maxSpeed_;
    }
    
    void SetMaxSpeed(int maxSpeed) override
    {
        maxSpeed_ = maxSpeed;
    }
    
private:
    int maxSpeed_;
};

class Proxy
{
public:
    Proxy()
        : isEnabled_(false)
    {}

    ~Proxy() = default;

    template<typename T, typename TMethod, typename... U>
    auto operator()(T* obj, TMethod fn, U... argv)
    {
        if (isEnabled_)
        {
            if (auto it = map_.find(obj); it != map_.end())
            {
                auto ptr = static_cast<T*>(it->second);
                return (ptr->*fn)(argv...);
            }
        }
        else
            return (obj->*fn)(argv...);
    }
    
    void SetEnabled(bool isEnabled)
    {
        isEnabled_ = isEnabled;
    }
    
    void SetMapping(std::unordered_map<void*, void*> const& map)
    {
        map_ = map;
    }

private:
    bool isEnabled_;
    std::unordered_map<void*, void*> map_;
};

int main(int argc, char const* argv[]) {

    ITransport* airplane = new Airplane();
    ITransport* car = new Car();

    std::unordered_map<void*, void*> map;
    map[car] = airplane;

    Proxy proxy;
    proxy.SetMapping(map);
    
    proxy.SetEnabled(false);
    proxy(car, &ITransport::WhoAmI);  // Car

    proxy.SetEnabled(true);
    proxy(car, &ITransport::WhoAmI);  // Airplane

    delete car;
    delete airplane;
    
    return EXIT_SUCCESS;
}
