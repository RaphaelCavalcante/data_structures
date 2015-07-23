<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
/*function download($file_name){
	
}

echo "<h1> Read Feed Test</h1>";
$feed = file_get_contents('http://www.mitografias.com.br/category/podcast/papo-lendario-podcast/feed/');
$rss=new SimpleXmlElement($feed);

//print_r($rss->item);
foreach($rss->channel->item as $entrada){
	echo '<p> <a href="'.$entrada->enclosure['url'].'"title="'.$entrada->title.'">'.$entrada->title.'</a></p>';

	//var_dump($entrada->enclosure);
}
*/

class ReadFeed{
	
	public function __construct(){
	}
	
	public function get_name($link){
		return basename($link,".mp3");
	}
	
	public function get_link_from_feed($feed_url){
		
		$rss= new SimpleXMLElement($feed_url);
		
		$files=array();


		foreach ($rss->channel->item as $link){
			//     var_dump($link->enclosure['url']);
			//     echo '<p>'.$link->enclosure["url"].'</p>';   
			//$podcast=fopen($link->enclosure['url'],'r');
			$url=$link->enclosure['url'];
	
			//echo "<p>".(curl_get_file_size($url))."</p>";
   
			array_push($files, $url);
			//file_put_contents(basename($link->enclosure['url']), $podcast);
			//     echo basename("".$podcast);
   
			//     var_dump($podcast);
			//$i++;
			//if($i>1){
			//  break;
			//}
		}
		return $files;
	}
	
	function curl_get_file_size( $url ) {
		// Assume failure.
		$result = -1;

		$curl = curl_init( $url );

		// Issue a HEAD request and follow any redirects.
		curl_setopt( $curl, CURLOPT_NOBODY, true );
		curl_setopt( $curl, CURLOPT_HEADER, true );
		curl_setopt( $curl, CURLOPT_RETURNTRANSFER, true );
		curl_setopt( $curl, CURLOPT_FOLLOWLOCATION, true );
		//curl_setopt( $curl, CURLOPT_USERAGENT, get_user_agent_string() );

		$data = curl_exec( $curl );
		curl_close( $curl );

		if( $data ) {
			$content_length = "unknown";
			$status = "unknown";

			if( preg_match( "/^HTTP\/1\.[01] (\d\d\d)/", $data, $matches ) ) {
				$status = (int)$matches[1];
			}
			if( preg_match( "/Content-Length: (\d+)/", $data, $matches ) ) {
				$content_length = (int)$matches[1];
			}

			// http://en.wikipedia.org/wiki/List_of_HTTP_status_codes
			if( $status == 200 || ($status > 300 && $status <= 308) ) {
				$result = $content_length;
			}
		}

		return $result;
	}
}


/*
$feed= file_get_contents('http://www.mitografias.com.br/category/podcast/papo-lendario-podcast/feed/');
$rss= new SimpleXMLElement($feed);

$i=0;
foreach ($rss->channel->item as $link){
//     var_dump($link->enclosure['url']);
//     echo '<p>'.$link->enclosure["url"].'</p>';   
    //$podcast=fopen($link->enclosure['url'],'r');
	$url=$link->enclosure['url'];
	
	echo "<p>".(curl_get_file_size($url))."</p>";
   
   
     //file_put_contents(basename($link->enclosure['url']), $podcast);
//     echo basename("".$podcast);
   
//     var_dump($podcast);
    //$i++;
    //if($i>1){
      //  break;
    //}
}*/