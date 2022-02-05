#include <iostream> 
using namespace std;
class Command
{
public:
	virtual void execute() = 0;
};
class Light 
{
public:
	void on() {
		cout << "the system in started\n";
	}
	void off() {
		cout << "the system is turned off\n";
	}
}; 
class LightOnCommand : public Command 
{
public:
        LightOnCommand(Light *light) : mLight(light) {}
	void execute(){
		mLight->on();
	}
private:
	Light *mLight;
};
class LightOffCommand : public Command 
{
public:
        LightOffCommand(Light *light) : mLight(light) {}
	void execute(){
		mLight->off();
	}
private:
	Light *mLight;
}; 
class Remotecon 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
private:
	Command *mCmd;
};
int main() 
{
	Light *light = new Light;
	LightOnCommand *lightOn = new LightOnCommand(light);
	LightOffCommand *lightOff = new LightOffCommand(light);
	Remotecon *con = new Remotecon;
	con->setCommand(lightOn); 
	con->buttonPressed();
	con->setCommand(lightOff);
	con->buttonPressed();

	delete light, lightOn, lightOff, con;

	return 0;
}
