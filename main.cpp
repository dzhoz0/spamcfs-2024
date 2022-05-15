#include<iostream>
#include<thread>
#include<cpr/cpr.h>
long long count = 0, tries = 0;
void submitForm() {
	// Request to get cookies for later use
	cpr::Response r = cpr::Get(cpr::Url{"https://surveynuts.com/surveys/take?id=241562&c=12337054481JPJL"});
	cpr::Cookies cookies = r.cookies; // Use this cookie on next requests
	// Print cookies
	//for (auto& cookie : cookies) {
		//std::cout << cookie.first << ": " << cookie.second << std::endl;
	//}
	r = cpr::Post(cpr::Url{"https://surveynuts.com/requests/log_this"},
			cookies,
			cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
			cpr::Body{"message=+QUESTIONS+2331389%2C2331390%2C2331388+OPTIONS+7503525%2C7503526%2C7503524+COMMENTS+lmaoo%2Clmao%2C<email>+<pass>+h%C6%A1i+non+NUMBERS+%2C%2C+SOURCE+UTOKENjy1xm667xnn"});	
	//std::cout << "==============================" << std::endl;
	//std::cout << r.text << std::endl;
	r = cpr::Post(cpr::Url{"https://surveynuts.com/requests/voteSurveySN"},
			cookies,
			cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
			cpr::Body{"question_id%5B%5D=2331389&question_id%5B%5D=2331390&question_id%5B%5D=2331388&option_id%5B%5D=7503525&option_id%5B%5D=7503526&option_id%5B%5D=7503524&text%5B%5D=lmao&text%5B%5D=lmao&text%5B%5D=spam+site+h%C6%A1i+non&number%5B%5D=&number%5B%5D=&number%5B%5D=&source=&utoken=jy1xm667xnn&surveyid=241562"});
	//std::cout << "==============================" << std::endl;
	//std::cout << r.text << std::endl;
	r = cpr::Post(cpr::Url{"https://surveynuts.com/request/update_sresults"},
			cookies,
			cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
			cpr::Body{"sid=241562"});
	
	r = cpr::Post(cpr::Url{"https://surveynuts.com/surveys/widget?id=237771&locale=en&c=7608689DLR"}, cookies);
	//std::cout << "==============================" << std::endl;
	//
	for(auto i: r.cookies) {
		std::cout << i.first << ": " << i.second << std::endl;
	}


	if(r.text.find("Thank you for taking this survey") != std::string::npos) {
		std::cout << "Successfully submitted form" << std::endl;
	} else {
		std::cout << "Failed to submit form" << std::endl;
	}




}
void loopedForm() {
	while(true) {
		submitForm();
	}
}
int main() {
// 	 spawn 10 threads of loopedForm
  const int THREADS = 50;
  std::vector<std::thread> threads;
  for (int i = 0; i < THREADS; i++) {
    threads.emplace_back(loopedForm);
  }
  for (auto &t : threads) {
    t.join();
  }
  	submitForm();


	return 0;
}
