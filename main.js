var express = require('express');
var bodyParser = require('body-parser');
var app = express();


app.get('/', function (req, res) {
  res.send(req.body);
  console.log("got a request 2" + req.tittle);
});


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
	extended: true
}));

app.post('/', function (req, res) {
  console.log(req.body);
  //if(req.body=getToken){
  //res.send(req.body);
  //res.set('Content-Type', 'text/html');    
  //res.send(req.body);
  res.send(new Buffer('whoop'));    
  //}
  console.log("got a request " + req.body.t);
});

app.listen(3001, function () {
  console.log('Example app listening on port 3001!');
});