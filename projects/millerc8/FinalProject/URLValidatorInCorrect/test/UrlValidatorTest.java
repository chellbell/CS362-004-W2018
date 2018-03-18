 public void testManualTest()
{
   // create new validator object
   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

   // manually create lists of sample valid & invalid URLs
   String[] validUrls = {
      "https://www.google.com",
      "http://www.google.com",
      "http://google.com",
      "google.com",
      "google.com/",
      "https://google.com/",
      "www.google.com",
      "www.google.com?msg=hello",
      "www.google.com/?msg=hello&hi=msg",
      "www.google.com/?msg=hi/",
      "http://google.com/?msg=hello"
      "google.com:64234",
      "www.google.com:240",
      "255:255:255:255",
      "entertainment720.com"
   };

   String[] invalidUrls = {
      "google/com",
      "!google.com",
      "www.!google.com",
      "wwwwwww.google.com",
      "httttps://www.google.com",
      "google.com?msg=hello?msg=hi?msg=sup",
      "//www.google.com",
      "http:google.com",
      "google.com/////",
      "https://www.google.com:hello?there",
      "https://google",
      "http://google.com:::",
      "goo..co:25",
      "0.0.0.0.0.0.0.0.00.0.0.0.0.0",
      "239595.333"
   };

   // check valid URLs
   // passing test (isValid true) prints a .
   for (int i = 0; i < validUrls.length; i++) {
      if (urlVal.isValid(validUrls[i])) {
         System.out.println(".");
      } else {
         System.out.println("x");
      }
   }

   // check invalid URLs
   // passing test (isValid false) print a .
   for (int i = 0; i < invalidUrls.length; i++) {
      if (!(urlVal.isValid(invalidUrls[i]))) {
         System.out.println(".");
      } else {
         System.out.println("x");
      }         
   }


}
