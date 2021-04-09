vuser_init()
{
	
/*Correlation comment - Do not change!  Original value='130993.231429729zHDHQztpDtVzzzzHtAtcHpHizAf' Name ='userSession' Type ='ResponseBased'*/

	web_reg_save_param_ex(
    "ParamName=Session", 
    "LB/IC=\"userSession\" value=\"",
    "RB/IC=\"/>",
    "Ordinal=1",
	LAST);

	web_url("webtours", 
		"URL={Host}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/* enter */
	
	web_submit_data("login.pl",
		"Action={Host}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer={Host}/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={Session}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=81", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		LAST);
	
	return 0;
}
