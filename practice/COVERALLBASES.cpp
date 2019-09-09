boost::gregorian::date dateObj1 { 2016, 3, 21 };
 
// Initializing Date object with 1st October 2016
boost::gregorian::date dateObj2 { 2016, 10, 1 };
 
// Get the Duration between 2 Dates
boost::gregorian::date_duration dur = dateObj2 - dateObj1;
 
// Fetch Days from date_duration object
std::cout<<"Difference b/w 2 Dates in days : "<<dur.days()<<std::endl;

g=dur.days();
f=dur.days();
years=g/(12*365);
mnths=f-years*12*365;
mnths=

