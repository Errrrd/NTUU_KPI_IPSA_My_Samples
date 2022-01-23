<!DOCTYPE html>
<html>
    <?php include 'includes/head.php'; ?>
    <body  bgcolor="#222222" class="style1">
        <?php include 'includes/script.php'; ?>
        <div id="wrapper" >
            <?php include 'includes/header.php'; ?>
            <?php include 'includes/sidebar.php'; ?>
            <div id="content" align="center" >
            <table border=0 align = center width = 740 height = 60  border-bottom = 0 border-top=0 background="/content/Forge_G.png"></table>
            <table border=0 align = center width = 740 background="/content/Forge_G.png">
<!-- Code for content -->
<?php
#create pathes and txt files (if don't have ".txt")
    if (!empty($_GET["newpath"])) {
        $path1 = $path2 = 'content/'.$_GET["newpath"];
        $path1 = $path1.'/image/';
        $path2 = $path2.'/text/';
        $d = dir($path1);
        if ($d) {
            $img_files = $txt_files = $html_txt = array();
            while (($name = $d->read()) !== false  ) {
                if ($name === '.' || $name === '..') continue;
                $FullName = $path1 . $name;

                if (is_file($FullName))
                {
                    $txt = $path2 . (substr($name, 0, -4)) . ".txt";
                    $img_files[] = $FullName;
                    $txt_files[] = $txt;
                    if (!is_file($txt))
                    {
                        $fp = fopen($txt, "w");
                        // записываем в файл текст
                        fwrite($fp, $name);
                        // закрываем
                        fclose($fp);
                    }
                    $html_txt[] = '<a href="javascript:doPopup('.'\''.$FullName.'\''.');">'.
                                '<img src='.'"'.$FullName.'"'.'width=140 border=0>';
                }
            }
            $d->close();
        }
#create table of pictures
        $size = count($img_files);
        #echo $size;
        #if(!empty($_GET["name"]))
        #{
        #    echo ($_GET["name"]);
        #    echo 'BBBBBBBBBBBB';
        #}
        #else echo 'AAAAAAAAAAAAAAAA';
        echo '<tr valign=top align = center>';
        #echo '<p align=center valign = top style="margin-left: 5; margin-right: 5">';


        for($i = 0; $i<$size; $i++ )
        {
            $is4 = ($i%4 === 3);

            echo "<td width=160> <font face=Arial size=3>";
            echo "<br/>";
            echo $html_txt[$i];
            echo "<br/>";
            if (is_file($txt_files[$i]))
            {
                include $txt_files[$i];
            }
            echo "</td>";
            if($is4) 
            {
                echo "</tr>";
                echo "<tr valign=top align = center>";
            }
        }
        #echo "<br/>";
        echo "</tr>";
    } else {
        echo '<tr valign=top align = center>';
        echo '<td width=720>';
        if(empty($_GET["pg"]))
            include $content;
        else if(($_GET["pg"]) == '1')
            include $contacts;
        else if(($_GET["pg"]) == '2')
            include $jrn;
        echo '</td>';
        echo '</tr>';
    }
?>
<!-- end code of content -->
            </table>
            <table border=0 align = center width = 740 height = 60  border-bottom=0 border-top=0 background="/content/Forge_G.png"></table>
            </div>
            <?php include 'includes/footer.php'; ?>
        </div> <!-- End #wrapper -->
    </body>
</html>