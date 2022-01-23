<?php include 'variables/variables.php'; ?>
  <!--______________________________________________________-->
  <SCRIPT LANGUAGE="JavaScript" TYPE="text/javascript">
      function doMenu(AObjIndex) { 
        var subObj = document.all['list_' + AObjIndex];

        if ( subObj.style.display == 'none' ) {
          subObj.style.display = 'block';
        }
        else {
          subObj.style.display = 'none';    
        }  
      }
      function doMenu1(AObjIndex) { 
        var subObj = document.all['list1_' + AObjIndex];

        if ( subObj.style.display == 'none' ) {
          subObj.style.display = 'block';
        }
        else {
          subObj.style.display = 'none';    
        }  
      }
  </SCRIPT>
  <!--______________________________________________________-->
  <SCRIPT LANGUAGE="JavaScript" TYPE="text/javascript">
      document.all['list1_1'].style.display = 'block';
      document.all['list_1'].style.display = 'block';
  </SCRIPT>
  <!--______________________________________________________-->
  <script language="javascript">
    function doPopup(popupPath) {
    window.open(popupPath,'name',
    'width=800,height=800,scrollbars=YES');
    }
  </script>