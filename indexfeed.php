<html>
<head>
<title> CastFeedDownload </title>
<?php

	require_once "readfeed.php";
	
	
	//$url='http://www.mitografias.com.br/category/podcast/papo-lendario-podcast/feed/';
	
	
	
	
	function saveUrl($home,$toSave){
		//echo $home['host']."<br> ".$toSave;
		$hosts[$home['host']]=$toSave;
		echo json_encode($hosts);
		//var_dump($hosts);
	}
	function showCasts(){
		$reader= new ReadFeed();
		$hosts=array();
		
		$url=$_POST['FEED_URL'];
		$feed=file_get_contents($url);
	
		$link=$reader->get_link_from_feed($feed);
		
			foreach ($link as $value){
			echo '<input type=checkbox name="'.$reader->get_name($value).'" value="'.$value.'" />'.$reader->get_name($value)."<br>";
	}
	}
?>
</head>
<body>

<?php

?>
<div style="position:fixed; left:10;top:0; bottom:0;">
	<br>
	<form action='indexfeed.php' method='post'>
		<input type='text' name='FEED_URL' placeholder='feed url'/>
		<input type='checkbox' name='save'> save url<br>
		<input type='submit' value='load podcasts'/>
	</form>
</div>
<?php
if(isset($_POST['FEED_URL'])){
	
?>
	
	
	<form action='download.php' method='post'>
	<div style="height: 500px;float: right; width: 800px; overflow:auto;">
	<h3> PODCASTS </h3>
	<?php
	
	if(isset($_POST['save'])){
		saveUrl(parse_url($_POST['FEED_URL']), $_POST['FEED_URL']);
	}
	showcasts();
	?>
	</div>
	<input style=" float:right;width:800px;"type='submit' value='download!' />
	
	</form>
	
	
<?php } ?>
</body>
</html>