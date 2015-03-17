<?php
	echo "<h2>Simple Twitter API Test</h2>";
	require_once('TwitterAPIExchange.php');
 
	/** Set access tokens here - see: https://dev.twitter.com/apps/ **/
	$settings = array(
					  'oauth_access_token' => "423025031-15zrdLMTM3RVwg4M3oznRbjZdtTUhXYkRDVoWPtZ",
					  'oauth_access_token_secret' => "V9euG8HM92S3Ak0skKkXk648fOwDJGXzbPikVvf7fxyMT",
					  'consumer_key' => "nksyKHebAbVIlXlGlZisiRIcF",
					  'consumer_secret' => "WYdrDbIBfgR69XpIGo0d4m9RT3s8vr8SERGpMLUOH7H5BDMyrA"
					  );
	$url = "https://api.twitter.com/1.1/statuses/user_timeline.json";
	$url2 = "https://api.twitter.com/1.1/statuses/home_timeline.json";
	$requestMethod = "GET";
	//if (isset($_GET['user']))  {$user = $_GET['user'];}  else {$user  = "babywhales101";}
	if (isset($_GET['count'])) {$user = $_GET['count'];} else {$count = 100;}
	
	$getfield = "?screen_name=$user&count=$count";
	$twitter = new TwitterAPIExchange($settings);
	$string = json_decode($twitter->setGetfield($getfield)
						  ->buildOauth($url2, $requestMethod)
						  ->performRequest(),$assoc = TRUE);
	
	if($string["errors"][0]["message"] != "") {echo "<h3>Sorry, there was a problem.</h3><p>Twitter returned the following error message:</p><p><em>".$string[errors][0]["message"]."</em></p>";exit();}
	
	foreach($string as $items)
	{
		echo "Time and Date of Tweet: ".$items['created_at']."<br />";
		echo "Tweet: ". $items['text']."<br />";
		echo "Tweeted by: ". $items['user']['name']."<br />";
		echo "Screen name: ". $items['user']['screen_name']."<br />";
		echo "Followers: ". $items['user']['followers_count']."<br />";
		echo "Friends: ". $items['user']['friends_count']."<br />";
		echo "favorites: ". $items['user']['favorite_count']."<br /><hr />";
	}
?>

