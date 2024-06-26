// express.js
const express = require("express");
const app = express();

app.get('/favicon.ico', (_, res) => {
  res.status(200);
})

// serve static files from /public
app.use(express.static("public"), (res, path, stat) => {
    if (path.endsWith('.wasm')) {
      res.set('Content-Type', 'application/wasm');
    }
  }
);

app.listen(2222, () => {
  console.log("Server running on port 2222");
});
