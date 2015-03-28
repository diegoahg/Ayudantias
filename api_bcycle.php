<?php
	$url = "https://portal.bikesharedev.com/1/subscriptiontypes/";
	//  Initiate curl
	$ch = curl_init();
	// Disable SSL verification
	curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "GET"); 
	
	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
	// Will return the response, if false it print the response
	
	
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	
	curl_setopt($ch, CURLOPT_HTTPHEADER, array('BCycle-Program-Token : fkIaYFsjmWzSgRdDLvWbXobb049ZVOvus36nUToZ77X0eIl1uhXpBxKKT1pu1vrk'));
	// Set the url
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1); 
	curl_setopt($ch, CURLOPT_URL,$url);
	// Execute
	$result = curl_exec($ch);
	// Closing
	curl_close($ch);
	
	if ($output === FALSE) {
         echo "cURL Error: " . curl_error($ch);
     }
	
	var_dump($result);

	// Will dump a beauty json :3
	$data = json_decode($result, true);
	
	//echo $data["error"];
?>