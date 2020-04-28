//<script>
// Requiring fs module in which
// readFile function is defined.
// const fs = require('fs')
//
// // Reading data in utf-8 format
// // which is a type of character set.
// // Instead of 'utf-8' it can be
// // other character set also like 'ascii'
//
// fs.readFile('Game.txt', 'utf-8', (err, data) => {
//     if (err) throw err;
//
//     // Converting Raw Buffer to text
//     // data using tostring function.
//     console.log(data);
// })
//</script>
var fs = require('fs');
var filename = "Game.txt";
fs.open(filename, 'r', function(err, fd)
{
  fs.watchFile(filename, function(cstat, pstat)
  {
    var delta = cstat.size - pstat.size;
    if (delta <= 0) return;

    fs.read(fd, new Buffer(delta), 0, delta, pstat.size, function(err, bytes, buffer)
    {
      console.log("err", err, "delta", delta, "bytes", bytes, "buffer", buffer.toString());
    });
  });
});

// var fs = require('fs');
// fs.readFile('Game.txt', 'utf8', function(err, contents)
// {
//     console.log(contents);
// });
//
// console.log('after calling readFile');


// function readTextFile(file)
// {
//   document.write("hello")
//     var rawFile = new XMLHttpRequest();
//     rawFile.open("Game.txt", file, false);
//     rawFile.onreadystatechange = function ()
//     {
//         if(rawFile.readyState === 4)
//         {
//             if(rawFile.status === 200 || rawFile.status == 0)
//             {
//                 var allText = rawFile.responseText;
//                 alert(allText);
//             }
//         }
//     }
//     rawFile.send(null);
// }

// var firstName;
// var secondName;
// var business;
// firstName = prompt("What is your name?");
// alert(firstName + " is not your name.");
// secondName = prompt("Enter your actual name.");
// while(firstName === secondName){
//         alert(firstName + " is not your name.");
//         secondName = prompt("Enter your actual name.");}
// if (firstName !== secondName){
// business = prompt("Okay " + secondName + ", what is your business here?");
// document.write("Sorry " + secondName + ", but your business of " + business + " is not welcome here, please leave the page.");}
