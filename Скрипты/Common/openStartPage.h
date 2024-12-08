openStartPage()
{
	lr_start_transaction("Open start page");
	
	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Priority", 
		"u=0, i");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param_ex(
        "ParamName=userSession",
        "LB=name\=userSession value\=",
        "RB=>",
        "Ordinal=3",
        "Notfound=warning",
        SEARCH_FILTERS,
        "Scope=BODY",  
        LAST);
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);
	
	web_url("WebTours", 
		"URL=http://127.0.0.1:8090/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Open start page", LR_PASS);
	return 0;
}