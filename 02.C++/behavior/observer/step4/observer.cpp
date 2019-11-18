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
class Observer
{
public:
    virtual void update(int temperature, int Presure, int Humidity) = 0;
    virtual void destroy() = 0;
    
    //virtual constructors 
    virtual ~Observer(){};
};

/*
* Interface
*/
class Subject
{
  public:
    virtual void registerObserver(Observer *pObserver) = 0;
    virtual void removeObserver(Observer *pObserver) = 0;
    virtual void notifyObserver() = 0;
};


class WeatherData :public virtual Subject
{
  public:
    void registerObserver(Observer *pObserver)
    {
        Observers.push_back(pObserver);
    }
    
    void removeObserver(Observer *pObserver)
    { 
       cout << "addr: " << pObserver<<endl;
        //@Todo : find and remove  this object
        Observers.erase (Observers.begin());
        delete pObserver;
        pObserver =NULL;
    }
    
    void notifyObserver()
    {
        cout<<"size= "<<Observers.size()<<endl;
    }
    
private:
    vector <Observer *> Observers;
    int temperature;
    int Presure;
    int Humidity;
};


class CurrentConditionsDisplay :public virtual  Observer
{
 public:
    
    CurrentConditionsDisplay(Subject *pWeatherData)
    {
        cout<<"CurrentConditionsDisplay()"<<endl;
        pWeatherData->registerObserver(this);
        this->pWeatherData =pWeatherData;
    }
    
    void update(int temperature, int Presure, int Humidity)
    {
        pWeatherData->notifyObserver();
    }
    
    void destroy()
    {
        pWeatherData->removeObserver(this);
    }
    
    ~CurrentConditionsDisplay()
    {
        cout<<"~CurrentConditionsDisplay()"<<endl;
    }
 private:
    //Store pointer  of WeatherData
    Subject *pWeatherData;
};

    
int main()
{
    Subject *pWeatherData = new WeatherData()  ;
    
    Observer *currentConditions = new CurrentConditionsDisplay(pWeatherData);
    currentConditions->update(1, 2, 3);
    currentConditions->destroy();
    cout << "addr of currentConditions: " << currentConditions<<endl;
   
    //currentConditions->update(1, 2, 3);
    
    pWeatherData->notifyObserver();
    //@Todo: Release memory
    
    return 0;
}