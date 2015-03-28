<?php
	
	// TO SEE IMPLEMENTATION: http://www3.nd.edu/~amcmaho4/testingTwitterapp/testtwitapi.php
	echo "<h2>Simple Twitter API Test</h2>";
	
	require_once('TwitterAPIExchange.php');
	
	
	// a php wrapper makes it easier to use my tokens  to make a connection to the twitter API
	// authentication
	$settings = array(
					  'oauth_access_token' => "423025031-15zrdLMTM3RVwg4M3oznRbjZdtTUhXYkRDVoWPtZ",
					  'oauth_access_token_secret' => "V9euG8HM92S3Ak0skKkXk648fOwDJGXzbPikVvf7fxyMT",
					  'consumer_key' => "nksyKHebAbVIlXlGlZisiRIcF",
					  'consumer_secret' => "WYdrDbIBfgR69XpIGo0d4m9RT3s8vr8SERGpMLUOH7H5BDMyrA"
					  );
	$url = "https://api.twitter.com/1.1/statuses/user_timeline.json";
	$url2 = "https://api.twitter.com/1.1/statuses/home_timeline.json";
	
	$requestMethod = "GET";
	// Uncommenting the comment below and then commenting the following if statement can very easily change what this does, you can fill in a public user name into the spot that says "babywhales101" .. this is just one of my friends.. and see tweets from that user
	//if (isset($_GET['user']))  {$user = $_GET['user'];}  else {$user  = "babywhales101";}
	
	// this if statement actually just sets the number of tweets that will be displayed from my feed, ie people that I follow
	if (isset($_GET['count'])) {$count = $_GET['count'];} else {$count = 100;}
	
	$getfield = "?screen_name=$user&count=$count"; // sets the screen name and account
	$twitter = new TwitterAPIExchange($settings);
	
	
	 this is the twitter request, it returns json
		$twitter->setGetfield($getfield)
		->buildOauth($url2, $requestMethod)
		->performRequest();
	echo $twitter->setGetfield($getfield)
	->buildOauth($url, $requestMethod)
	->performRequest()> ;
	
	
	// json_decode is a php function converts JSON string into an object or an associative array (dictionary)
	// without this the output would be in json
	//$string = json_decode($twitter->setGetfield($getfield)
						  //->buildOauth($url2, $requestMethod)
						  //->performRequest(),$assoc = TRUE);
	
	if($string["errors"][0]["message"] != "") {echo "<h3>Sorry, there was a problem.</h3><p>Twitter returned the following error message:</p><p><em>".$string[errors][0]["message"]."</em></p>";exit();}
	
	// the $items is an identifier that is the element at the current index in the matrix, so this for loop just loops through the string dictionary and echos selected values
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
