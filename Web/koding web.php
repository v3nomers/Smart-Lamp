<!DOCTYPE html>
<html>
<head>

<meta http-equiv="refresh" content="5">



<h1>
<img src="slam.png" alt="slam picture" align="center" style=" width:300px;height:150px;">
<img src="light the world.png" alt="slam picture" align="right" style=" width:500px;height:150px;">
</h1>
<h2>
<style>
ul {
	
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333333;
}

li {
    float: left;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 30px;
    text-decoration: none;
}

li a:hover {
    background-color: #111111;
}

.imgContainer{
    float:left;
}

</style>
</h2>
</head>
<body>

<ul>
  <li><a class="active"href="/web/beranda.html">Home</a></li>
  <li><a href="#news">News</a></li>
  <li><a href="#contact">Contact</a></li>
  <li><a href="#about">About</a></li>
</ul>
<h1 style="text-align:center;">
System Kontrol Lampu
</h1>




 <p style= "font-family:Comic Sans MS;font-size:125%;"> </p>
 <p style="font-family:verdana;">Lampu Menggunakan Sensor</p>
 <pre>                lampu 1                                           Lampu 2                               lampu 3 </pre>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==0){print '<div class="imgContainer"><img src="lampu mati.png" hspace="20"> </div> ';}
			if($bt==1){print '<div class="imgContainer"><img src="lampu mekan.png" hspace="20"> </div>';}
		?>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==1){print '<div class="imgContainer"><img src="lampu mati.png" hspace="100"> </div> ';}
			if($bt==0){print '<div class="imgContainer"><img src="lampu mekan.png" hspace="100"> </div>';}
		?>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==1){print '<div class="imgContainer"><img src="lampu mati.png" > </div> ';}
			if($bt==0){print '<div class="imgContainer"><img src="lampu mekan.png" > </div>';}
		?>
		<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
     <pre><input type="button" value="Turn On" hspace="100" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">   <input type="button" value="Turn On" hspace="180" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">   <input type="button" value="Turn On" hspace="80" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'"></pre>
	 <pre><input type="button" value="Turn off" hspace="100" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=COA52U9U4KFT6CMS'">   <input type="button" value="Turn off" hspace="180" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">  <input type="button" value="Turn off" hspace="90" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'"></pre> 	 
<br><br>
	 <p style="font-family:verdana;">Lampu Menggunakan Sensor</p>
 <pre>                lampu 1                             Lampu 2                                          lampu 3 </pre>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==0){print '<div class="imgContainer"><img src="lampu mati.png" hspace="20"> </div> ';}
			if($bt==1){print '<div class="imgContainer"><img src="lampu mekan.png" hspace="20"> </div>';}
		?>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==1){print '<div class="imgContainer"><img src="lampu mati.png" hspace="100"> </div> ';}
			if($bt==0){print '<div class="imgContainer"><img src="lampu mekan.png" hspace="100"> </div>';}
		?>
		<?php
			$bt=file_get_contents("https://api.thingspeak.com/channels/149570/fields/1/last.txt");
			if($bt==1){print '<div class="imgContainer"><img src="lampu mati.png" > </div> ';}
			if($bt==0){print '<div class="imgContainer"><img src="lampu mekan.png" > </div>';}
		?>
		<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
     <pre><input type="button" value="Turn On" hspace="100" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">   <input type="button" value="Turn On" hspace="175" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">   <input type="button" value="Turn On" hspace="80" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'"></pre>
	 <pre><input type="button" value="Turn off" hspace="100" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">   <input type="button" value="Turn off" hspace="175" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'">  <input type="button" value="Turn off" hspace="90" onclick="window.location.href='https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI'"></pre> 	

</body>

<footer class="page-footer">
      
        </footer>
</html>

