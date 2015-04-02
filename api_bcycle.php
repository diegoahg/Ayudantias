<?php

$url = "https://portal.bikesharedev.com/1/subscriptiontypes";

$ch = curl_init();
$opciones = array(
    CURLOPT_HTTPHEADER => array('BCycle-Program-Token : fkIaYFsjmWzSgRdDLvWbXobb049ZVOvus36nUToZ77X0eIl1uhXpBxKKT1pu1vrk'),
    CURLOPT_URL => 'https://portal.bikesharedev.com/1/subscriptiontypes',
    CURLOPT_RETURNTRANSFER => 1,
    CURLOPT_VERBOSE => 1,
    CURLINFO_HEADER_OUT => 1,
    CURLOPT_SSL_VERIFYPEER => false
);
curl_setopt_array($ch, $opciones);

$result = curl_exec($ch);
if ($result === FALSE) {
    echo "cURL Error: " . curl_error($ch);
} else {
    curl_close($ch);

    $data = json_decode($result, true);
    
    echo $data["stackTrace"];
}
