$(document).ready(function () {
  $(".btn1").click(function () {
    $(".gallery-1").show();
    $(".gallery-2").hide();
    $(".gallery-3").hide();
    $(".gallery-4").hide();
  });

  $(".btn2").click(function () {
    $(".gallery-2").show();
    $(".gallery-1").hide();
    $(".gallery-3").hide();
    $(".gallery-4").hide();
  });

  $(".btn3").click(function () {
    $(".gallery-3").show();
    $(".gallery-2").hide();
    $(".gallery-1").hide();
    $(".gallery-4").hide();
  });
  $(".btn4").click(function () {
    $(".gallery-4").show();
    $(".gallery-2").hide();
    $(".gallery-3").hide();
    $(".gallery-1").hide();
  });
});
