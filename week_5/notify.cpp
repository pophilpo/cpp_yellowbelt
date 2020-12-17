#include <iostream>
#include <string>


using namespace std;


void SendSms(const string& number, const string& message){

	cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& addr, const string& message){
	cout << "Send '" << message << "' to e-mail " << addr << endl;

}


class INotifier {
	public:

		virtual void Notify(const string& message) const = 0;
};


class SmsNotifier : public INotifier {
	private:
		const string number;
	public:
		SmsNotifier(const string& number): number(number) {}

		void Notify(const string& message) const override {
			SendSms(number, message);
		}
};

class EmailNotifier : public INotifier {
	private:
		const string addr;
	public:
		EmailNotifier(const string& email): addr(email){}

		void Notify(const string& message) const override{
			SendEmail(addr, message);
		}

};


void Notify(INotifier& notifier, const string& message){
	notifier.Notify(message);
}
