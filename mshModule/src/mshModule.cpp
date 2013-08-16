//============================================================================
// Name        : mshModule.cpp
// Author      : Mohammad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <urbi/uobject.hh>
#include <urbi/uclient.hh>

using namespace std;
using namespace urbi;

class myModule : public urbi :: UObject
{
	private:
//		UVar uVar;

	public:
		int init();
		myModule(const string &n);
//		int uVarChange(UVar& var);
		void moveEyes(int counter);
		void moveEyesCircle(int counter);
		void moveNeck(int counter);
		void moveEars(int counter);
		void moveEyeLids(int counter);
		void moveMouth(int counter);
		void changeLEDColors(int counter);
		void testReeti(int counter, int loops);
};

UStart(myModule);

myModule::myModule(const string &n):UObject(n)
{
	UBindFunction(myModule,init);
}

int myModule::init()
{
//	UBindVar(myModule,uVar);

//	UNotifyChange(uVar, &myModule::uVarChange);

	UBindFunction(myModule, moveEyes);
	UBindFunction(myModule, moveEyesCircle);
	UBindFunction(myModule, moveNeck);
	UBindFunction(myModule, moveEars);
	UBindFunction(myModule, moveEyeLids);
	UBindFunction(myModule, moveMouth);
	UBindFunction(myModule, changeLEDColors);
	UBindFunction(myModule, testReeti);

	return 0;
}

void myModule::moveEyes(int counter)
{
	int cnt = 0;

	stringstream strMessage;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.rightEyePan=0,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=0,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=100,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=100,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=0,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=100,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=100,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=0,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=0,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=0; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=100,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=100; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=0,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=100; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=100,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=0; sleep(1s);";

		strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
		strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50; sleep(1s);";

		send(strMessage.str());
		strMessage.str(string());
	}
}

void myModule::moveEyesCircle(int counter)
{
	stringstream strMessage;

	int x = 0, y = 0, cnt = 0;

	while(cnt++ < counter)
	{
		while(x <= 100)
		{
			y = sqrt(2500-pow(((double)x-50),2)) + 50;
			strMessage << "Global.servo.rightEyePan=" << x << ",Global.servo.rightEyeTilt=" << y << ",";
			strMessage << "Global.servo.leftEyePan=" << x << ",Global.servo.leftEyeTilt=" << y << ";";
			send(strMessage.str());
			strMessage.str(string());
			x += 2;
		}

		x = 100;

		while(x >= 0)
		{
			y = -sqrt(2500-pow(((double)x-50),2)) + 50;
			strMessage << "Global.servo.rightEyePan=" << x << ",Global.servo.rightEyeTilt=" << y << ",";
			strMessage << "Global.servo.leftEyePan=" << x << ",Global.servo.leftEyeTilt=" << y << ";";
			send(strMessage.str());
			strMessage.str(string());
			x -= 2;
		}
	}

	strMessage << "Global.servo.rightEyePan=50,Global.servo.rightEyeTilt=50,";
	strMessage << "Global.servo.leftEyePan=50,Global.servo.leftEyeTilt=50;";
	send(strMessage.str());
	strMessage.str(string());
}

void myModule::moveNeck(int counter)
{
	stringstream strMessage;

	int cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.neckRotat=0,Global.servo.neckPan=50,Global.servo.neckTilt=50; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.neckRotat=100,Global.servo.neckPan=50,Global.servo.neckTilt=50; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.neckRotat=50,Global.servo.neckPan=0,Global.servo.neckTilt=50; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.neckRotat=50,Global.servo.neckPan=100,Global.servo.neckTilt=50; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.neckRotat=50,Global.servo.neckPan=50,Global.servo.neckTilt=0; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.neckRotat=50,Global.servo.neckPan=50,Global.servo.neckTilt=100; sleep(2s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	strMessage << "Global.servo.neckRotat=50,Global.servo.neckPan=50,Global.servo.neckTilt=50;";
	send(strMessage.str());
	strMessage.str(string());
}

void myModule::moveEars(int counter)
{
	stringstream strMessage;

	int cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.leftEar=0,Global.servo.rightEar=0; sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.leftEar=100,Global.servo.rightEar=100; sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.leftEar=0,Global.servo.rightEar=100; sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.leftEar=100,Global.servo.rightEar=0; sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	strMessage << "Global.servo.leftEar=50,Global.servo.rightEar=50;";
	send(strMessage.str());
	strMessage.str(string());
}

void myModule::moveEyeLids(int counter)
{
	stringstream strMessage;

	int cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.leftEyeLid=0,Global.servo.rightEyeLid=0, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.leftEyeLid=100,Global.servo.rightEyeLid=100, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());
	}
}

void myModule::changeLEDColors(int counter)
{
	stringstream strMessage;

	int cnt = 0;

	while(cnt++ < counter)
	{
		for(int r = 0 ; r <= 255 ; r += 15)
		{
			for(int g = 0 ; g <= 255 ; g += 15)
			{
				for(int b = 0 ; b <= 255 ; b += 15)
				{
					strMessage << "Global.servo.changeLedColorRGB(0," << r << "," << g << "," << b << ",1);";
					send(strMessage.str());
					strMessage.str(string());
				}
			}
		}
	}

	strMessage << "Global.servo.changeLedColorRGB(0,0,0,0,0);";
	send(strMessage.str());
	strMessage.str(string());
}

void myModule::moveMouth(int counter)
{
	stringstream strMessage;

	int cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.leftLC=0,Global.servo.rightLC=0, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.leftLC=100,Global.servo.rightLC=100, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	cnt = 0;

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.topLip=0,Global.servo.bottomLip=0, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.topLip=100,Global.servo.bottomLip=100, sleep(1s);";
		send(strMessage.str());
		strMessage.str(string());
	}

	cnt = 0;

	strMessage << "Global.servo.leftLC=50,Global.servo.rightLC=50;";
	send(strMessage.str());
	strMessage.str(string());

	while(cnt++ < counter)
	{
		strMessage << "Global.servo.topLip=0,Global.servo.bottomLip=100, sleep(0.5s);";
		send(strMessage.str());
		strMessage.str(string());

		strMessage << "Global.servo.topLip=100,Global.servo.bottomLip=0, sleep(0.5s);";
		send(strMessage.str());
		strMessage.str(string());
	}
}

void myModule::testReeti(int counter, int loops)
{
	int cnt = 0;

	while(cnt++ < loops)
	{
		moveEyesCircle(counter);
		moveEyes(counter);
		moveNeck(counter);
		moveEars(counter);
		moveEyeLids(counter);
		moveMouth(counter);
		changeLEDColors(1);
	}
}

//int myModule::uVarChange(UVar& _uVar)
//{
//	send("Global.servo.color=Global.GreetTime.color;");
//
//	return 0;
//}

//int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	return 0;
//}
