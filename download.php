<?php

function download_file_v2($filepath){
	$fp = fopen (basename($filepath), 'w+'); // Output file
	$ch = curl_init($filepath); // Input file
	curl_setopt($ch, CURLOPT_TIMEOUT, 50);
	curl_setopt($ch, CURLOPT_FILE, $fp);
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
	curl_exec($ch);
	curl_close($ch);
	fclose($fp);
}

	function download_remote_file_with_curl($file_url, $save_to)
	{
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_POST, 0); 
		curl_setopt($ch,CURLOPT_URL,$file_url); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
		$file_content = curl_exec($ch);
		curl_close($ch);
 
		$downloaded_file = fopen($save_to, 'w');
		fwrite($downloaded_file, $file_content);
		fclose($downloaded_file);
 
	}
	
	function download_remote_file_with_fopen($file_url, $save_to)
	{
		$in=    fopen($file_url, "rb");
		$out=   fopen($save_to, "wb");
 
		while ($chunk = fread($in,8192))
		{
			fwrite($out, $chunk, 8192);
		}
 
		fclose($in);
		fclose($out);
	}
	
	function download_remote_file($file_url, $save_to)
	{
		$content = file_get_contents($file_url);
		file_put_contents($save_to, $content);
	}
function download_file_v3($filepath){
	$file=basename($filepath);
	$filedownload=@fopen($filepath,'w+');
	set_time_limit(0);
	if (file_exists($file)) {
		header('Content-Type: application/csv');
		header('Content-Disposition: attachment; filename=example.csv');
		header('Pragma: no-cache');
		readfile("/path/to/yourfile.csv");
		exit;
	}else{
		echo "file does not exists";
	}
}
function download_file_v4($filepath){
	header("Content-type: application/x-file-to-save");
	header("Content-Disposition: attachment; filename=".basename($filepath));
	
	//readfile($_REQUEST['file']);	
	readfile($filepath);
}
function download_file($filepath){
	$DOWNLOADS="downloads/";
//	echo $filepath;
	$podcast=fopen($filepath,'r');
	file_put_contents(basename($filepath),$podcast);
	
}
//var_dump($_POST);

if(!empty($_POST)){
	echo sizeof($_POST);
	ini_set('max_execution_time',0);
	foreach($_POST as $url){
		download_file_v4($url);
		//download_remote_file_with_curl($url, basename($url));
		//download_remote_file($url, basename($url));
	}
}