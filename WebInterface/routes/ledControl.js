var express = require('express');
var router = express.Router();

/* GET LED Control page. */
router.get('/ledControl', function (req, res) {
   console.log({location: 'ledControl.js::router.get (req.params): ', msg: req.params});
   res.render('ledControl', {         // pass vars to the render template
      pageTitle: 'LED Control',
      pageID: 'led_control'
   });
});

/* Post Ajax request. */
router.post('/ledControl', function (req, res) {
   console.log({location: 'ledControl.js::router.post (req.params): ', msg: req.body});
   // res.render('ledControlAjax', {         // pass vars to the render template
   //    pageTitle: 'LED Control::Ajax',
   //    pageID: 'led_control'
   // });
   res.send({pageTitle: 'Tesing Ajax'});
});

module.exports = router;