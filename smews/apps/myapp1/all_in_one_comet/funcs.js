var ajaxTarget = 'test';

function init(){
	document.getElementById("loader").style.visibility = "hidden";
}

/*function ajaxCallback(status,text){
	if(status == 200 && text != "") {
		text = parseInt(text/10.24);
		document.getElementById("alert").innerHTML="CPU Usage: " + text + " %";
	}
}*/

function run(){
	document.getElementById("joystick").innerHTML = "";
	joystick = Number(document.getElementById("joystick").value);
	if(isNaN(joystick))
		joystick = -1;
	
	doAjax(ajaxTarget+"?joystick="+joystick,ajaxCallback,0,0);
}

function doAjax(ajaxTarget,ajaxCallBack,timeout,timeoutCallBack){
	var xhr;
	var xhrTimer;
	try{ xhr = new XMLHttpRequest(); }
	catch(e){ xhr = new ActiveXObject('Microsoft.XMLHTTP'); }
	xhr.onreadystatechange = function(){
		if(xhr.readyState == 4) {
			ajaxCallBack(xhr.status,xhr.responseText);
			if(timeout > 0)
				clearTimeout(xhrTimer);
		}
	};
	xhr.open("GET", ajaxTarget, true);
	if(timeout > 0)
		xhrTimer = setTimeout(function() { xhr.abort(); timeoutCallBack();}, timeout);
	xhr.send(null);
}

function ajaxGet(url) {
	var xhr;
	try{ xhr = new XMLHttpRequest(); }
	catch(e){ xhr = new ActiveXObject('Microsoft.XMLHTTP'); }

	xhr.onreadystatechange = function(){
		if(xhr.readyState  == 4){
			if(ajaxRet=xhr.status==200)
				ajaxCallback(xhr.responseText);
		}
	};
	xhr.open("GET", url, true);
	xhr.send(null);
}
