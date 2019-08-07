# check-caps
Native node module to check if caps lock is on/off (Windows, Mac OS, Linux)

```js
const checkcaps = require('check-caps');
// get the status of caps lock (boolean)..
checkcaps.status();
```

# Support
- (✔) Windows
- (✔) Mac OS 
- (✔) Linux

*Note* Both Mac OS and Linux support is based on ``X11/XKBlib.h``

# Build
To build locally on your machine
```bash
$ npm run build-addon
```

# License
### MIT