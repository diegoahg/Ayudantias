<?php
$directorios= array(
			"TT.OO y Agencias"=>118,
			"Alimentación"=>152,
			"Alojamiento"=>434,
			"Transporte"=>69,
			"Esparcimiento"=>118,
			"Turismo Aventura"=>31,
			"Guias de Turismo"=>84
			);
//ciclo de Directorios
for($i=1;$i<2;$i++)
{
	//Ciclo de Paginas
	
?>
<script>
var variablejs = Math.random() ;
document.cookie ='variable='+variablejs+'; expires=Thu, 2 Aug 2021 20:47:11 UTC; path=/';
</script>
<?php
$_GET["nocache"]=$_COOKIE["variable"];
$directorio2 ='3';
$region = '0';
$tipo = '0';
$calificacion = '0';
$comuna = '0';
$sello = '1';
$sellos = '1';
$localidadcomuna = '';
$nombreservicio = '';
$directorio = '1';
$page = '1';
$lang = '';
 $data = array("directorio2" => $directorio2,
				"region" => $region,
				"tipo" => $tipo,
				"calificacion" => $calificacion,
				"comuna" => $comuna,
				"sello" => $sello,
				"sellos" => $sellos,
				"localidadcomuna" => $localidadcomuna,
				"nombreservicio" => $nombreservicio,
				"directorio" => $directorio,
				"page" => $page,
				"lang" => $lang,
			);
$url = "http://act.sernatur.cl/ACT2/wsearch/wensearch.php?nocache=".$_COOKIE["variable"];
echo $url." ".$_GET["nocache"];
$parametros_post = 'region='.urlencode($region).'&directorio2='.urlencode($directorio2).'&tipo='.urlencode($tipo).'&calificacion='.urlencode($calificacion).'&comuna='.urlencode($comuna).'&localidadcomuna='.urlencode($localidadcomuna).'&nombreservicio='.urlencode($nombreservicio).'&directorio='.urlencode($directorio).'&page='.urlencode($page).'&lang='.urlencode($lang).'&sello='.urlencode($sello).'&sellos='.urlencode($sellos); 
 //$parametros_post = 'region='.$region."&directorio2=".$directorio2.'&tipo='.$tipo.'&calificacion='.$calificacion.'&comuna='.$comuna.'&localidadcomuna='.$localidadcomuna.'&nombreservicio='.$nombreservicio.'&directorio='.$directorio.'&page='.$page.'&lang='.$lang; 
 echo  "<br>".$parametros_post;
   //Usamos cUrl para obtener la página web deseada (usamos cUrl para mayor seguridad)
  //Iniciamos pasandole la ruta de la página deseada, con el parámetro pagina que aumentará en cada iteración del bucle for
  $curl = curl_init();
   curl_setopt($curl, CURLOPT_URL, $url);
  // definir tipo de petición a realizar: POST
  //curl_setopt ($curl, CURLOPT_POST, 1
curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "POST");  
  // Le pasamos los parámetros definidos anteriormente
  curl_setopt ($curl, CURLOPT_POSTFIELDS,http_build_query($data)); 
  // sólo queremos que nos devuelva la respuesta	
  //curl_setopt($curl, CURLOPT_HEADER, false);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
 // curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
 // curl_setopt($curl, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.224 Safari/534.10');
 
  //Asignamos los datos obtenidos a la variable $html
  $html = curl_exec($curl);
  //Cerramos la operacion cUrl
  curl_close($curl);
  echo  $html;
  
  $oldSetting = libxml_use_internal_errors( true );
  libxml_clear_errors();
  //(.*?) es donde desea recatar el dato
//$dato = $url.";";
//echo $html
/*
if ( preg_match('|<h1 class="m-business-card--name" itemprop="name">(.*?)</h1>|is' , $html , $contenido ) )
{
	$nombre = utf8_decode($contenido[1]);
	$dato .= $nombre.";";
	
}
else
{
$dato.=";";
}
*/
}
?>