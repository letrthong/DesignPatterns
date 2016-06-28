#include <iostream>
using namespace std;
#include <vector>

class Device
{
public:
    Device(int ID)
    {
        mID = ID;
    }
    
    void display()
    {
        cout <<"Device ID= "<< mID <<endl;
    }
private:
    int mID;
};

class Server
{
public:
        void addDevice(Device *p)
        {
             Devices.push_back(p);
        }
        void removeDevice(Device *p )
        {
            //@Todo: ThongLT
        }
    
        void update()
        {
           for(int ii=0; ii < Devices.size(); ii++)
           {
              Devices[ii]->display();
           }
        }
    
private :
    std::vector<Device *> Devices;

};


int main()
{
    Server  *pDevices = new Server();
    pDevices->addDevice(new Device(1));
    pDevices->addDevice(new Device(2));
    pDevices->update();
  
    //@ToDo:Memory Leak
    return 0;
}