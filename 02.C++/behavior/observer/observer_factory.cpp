/*
*observer.cpp
*Author:ThongLT
*/
#include <iostream>
#include <vector>
using namespace std;

/*
*Interface
*/
class Observer {
public:
    virtual void update(int temperature, int Presure, int Humidity) = 0;
    virtual void destroy() = 0;

    //virtual constructors
    virtual ~Observer(){};
};

/*
* Interface
*/
class Subject {
public:
    virtual void registerObserver(Observer* pObserver) = 0;
    virtual void removeObserver(Observer* pObserver) = 0;
    virtual void notifyObserver() = 0;
};

class WeatherData : public virtual Subject {
public:
    void registerObserver(Observer* pObserver)
    {
        Observers.push_back(pObserver);
    }

    void removeObserver(Observer* pObserver)
    {
        cout << "addr: " << pObserver << endl;
        //@Todo : find and remove  this object
        Observers.erase(Observers.begin());
        /*delete pObserver;
        pObserver = NULL;*/
    }

    void notifyObserver()
    {
        cout << "notifyObserver::size= " << Observers.size() << endl;
    }

private:
    vector<Observer*> Observers;
    int temperature;
    int Presure;
    int Humidity;
};

class ObserverBase : public virtual Observer {
public:
    ObserverBase(Subject* pWeatherData)
    {
        cout << "ObserverBase()" << endl;
        pWeatherData->registerObserver(this);
        this->_pWeatherData = pWeatherData;
    }

    void update(int temperature, int Presure, int Humidity)
    {
        if (_pWeatherData != NULL) {
            _pWeatherData->notifyObserver();
        }
    }

    void destroy()
    {
        if (_pWeatherData) {
            _pWeatherData->removeObserver(this);
            _pWeatherData = NULL;
        }
    }

    ~ObserverBase()
    {
        cout << "~ObserverBase()" << endl;
    }

protected:
    //Store pointer  of WeatherData
    Subject* _pWeatherData;
};

class CurrentConditionsDisplay : public ObserverBase {
public:
    CurrentConditionsDisplay(Subject* pWeatherData)
        : ObserverBase(pWeatherData)
    {
    }
};

int main()
{
    Subject* pWeatherData = new WeatherData();

    pWeatherData->notifyObserver();

    ObserverBase* pcurrentConditions = new CurrentConditionsDisplay(pWeatherData);

    pWeatherData->notifyObserver();

    pcurrentConditions->update(1, 2, 3);
    pcurrentConditions->destroy();

    pcurrentConditions->update(1, 2, 3);

    pWeatherData->notifyObserver();
    
    delete pcurrentConditions;
    delete pWeatherData;

    return 0;
}
