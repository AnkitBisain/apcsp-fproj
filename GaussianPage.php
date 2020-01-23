<!DOCTYPE html>
<html>
  <head>
    <title>Form Input 2</title>
	 <link rel="stylesheet" href="styles.css">
  </head>


  <body>

    <h1>Complex Number Factoring</h1>
    <p>This program lets you input any complex number (as long as both parts are whole numbers) and the factors the complex number.</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $output = $retc = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
         exec("/usr/lib/cgi-bin/sp1b/gaussianfactor " . $arg1 . " " . $arg2, $output, $retc); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Re: <input type="text" name="arg1"><br>
      Im: <input type="text" name="arg2"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h2>Your Input:</h2>";
         echo $arg1;
         echo "<br>";
         echo $arg2;
         echo "<br>";
	 echo "Complex Number input:";
	 echo "<br>";
	 echo "$arg1+$arg2*i";
 	 echo "<br>";

       
         echo "<h2>Factored Result:</h2>";
	 echo "$arg1+$arg2*i=";
	 echo "<br>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
