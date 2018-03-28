var express = require('express');
var reload = require('reload');
var bodyParser = require('body-parser');
// var fs = require('fs');
// var wss = new require('ws').Server({port: 3030});
var app = express();

app.set('port', process.env.PORT || 3000);
app.set('view engine', 'ejs');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

app.use(require('./routes/index'));
app.use(require('./routes/ledControl'));
app.use('/jquery', express.static('./node_modules/jquery/dist'));
app.use(express.static('./public'));

// global vars for the EJS (Embedded JavaScript) framework
app.locals.siteTitle = 'RL'; // RoboLed siteTitle

var server = app.listen(app.get('port'), function () {
   console.log('Example app listening on port: ' + app.get('port') + '!');
});

reload(app);
