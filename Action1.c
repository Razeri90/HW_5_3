Action1()
{
	/* Itinerary */
	
//	//Цена 3-х билетов
//	web_reg_save_param_ex(
//    	"ParamName=City", 
//    	"LB/IC=Total Charge: $ ", 				//Ограничение слева
//    	"RB/IC=<BR/>",							//Ограничение справа
//    	"Ordinal=All", 							//Какое значение взять
//	LAST); 
	
	web_reg_save_param_ex(
		"ParamName=City",
	    "LB= leaves ",
	    "RB=  for ",
	    "Ordinal=ALL",
	LAST);
	
	web_reg_save_param_ex(
		"ParamName=TotalFlights",
		"LB=A total of",
		"RB=scheduled flights.",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	

	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
  	lr_output_message("1 City depart=%s",(lr_eval_string("{City_1}")));
	lr_output_message("2 City depart=%s",(lr_eval_string("{City_2}")));
	lr_output_message("3 City depart=%s",(lr_eval_string("{City_3}")));
	lr_output_message("Total flights=%d",(atoi(lr_eval_string("{TotalFlights}"))));

    if(strcmp(lr_eval_string("{City_1}"), str)!=0){
	    lr_output_message("Delete first City");
		lr_save_string("1","flighcount");   
	}
	 if(strcmp(lr_eval_string("{City_2}"), str)!=0){
	    lr_output_message("Delete second City");
		lr_save_string("2","flighcount");  
	}
	 if(strcmp(lr_eval_string("{City_3}"), str)!=0){
	    lr_output_message("Delete third City");
		lr_save_string("3","flighcount");   
	}
		

//Запрос на отмену
	web_submit_form("itinerary.pl",ITEMDATA,
       "Name={flighcount}", "Value=on",ENDITEM,          //Постановка значения
       "Name=removeFlights.x","Value=36",ENDITEM,
       "Name=removeFlights.y","Value=5",ENDITEM,
       LAST);
	

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=flightID", "Value={flightID}", ENDITEM, 
		"Name=flightID", "Value={flightID}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=34", ENDITEM, 
		"Name=removeFlights.y", "Value=11", ENDITEM, 
		LAST);
	return 0;
}