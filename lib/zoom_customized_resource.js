// const { ZoomSDKError } = require('./settings.js');
// const messages = require('./electron_sdk_pb.js');

// var ZoomCustomizedResource = (function () {
//   var instance;
//   /**
//    * Zoom Customized Resource
//    * @module zoom_customized_resource
//    * @return {ZoomCustomizedResource}
//    */
//   function init(opts) { 
//     var clientOpts = opts || {};

//     // Private methods and variables
//     var _addon = clientOpts.addon.GetCustomizedResourceObj() || null;

//     return {


//       /**
//       * Add the custom photo files, currently, support PNG and SVG formats. 
//       * You must call the function first before calling InitSDK(), or no, it won't work.
//       * @method Resource_AddCustomizedPictureResource
//       * @param {String} strPNGID Resource ID corresponding to the custom resource.
//       * @param {String} strPNGPath The location of the customized resource file must be an absolute path and include the file name with suffix.
//       * @return {Number} Defined in: {@link ZoomSDKError}
//       */
//       Resource_AddCustomizedPictureResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let strPNGID = clientOpts.strPNGID;
//           let strPNGPath = clientOpts.strPNGPath;
//           try {
//             let AddCustomizedPictureResourceParams = new messages.AddCustomizedPictureResourceParams();
//             AddCustomizedPictureResourceParams.setStrpngid(strPNGID);
//             AddCustomizedPictureResourceParams.setStrpngpath(strPNGPath);
//             let bytes = AddCustomizedPictureResourceParams.serializeBinary();
//             return _addon.AddCustomizedPictureResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       },
//       /**
//       * Use the custom string to replace the specified string item.
//       * If customizedString is NULL or is not NULL but with length zero(0), the return value is SDKERR_INVALID_PARAMETER.
// 	    * You must call the function first before calling InitSDK(), or no, it won't work.
//       * @method Resource_AddCustomizedStringResource
//       * @param {String} CustomizedStringType Specify the string item type. Defined in: {@link SDKCustomizedStringType}
//       * @param {String} strCustomizedString Specify the custom string.
//       * @return {Number} Defined in: {@link ZoomSDKError}
//       */
//       Resource_AddCustomizedStringResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let CustomizedStringType = clientOpts.CustomizedStringType;
//           let strCustomizedString = clientOpts.strCustomizedString;
//           try {
//             let AddCustomizedStringResourceParams = new messages.AddCustomizedStringResourceParams();
//             AddCustomizedStringResourceParams.setCustomizedstringtype(CustomizedStringType);
//             AddCustomizedStringResourceParams.setStrcustomizedstring(strCustomizedString);
//             let bytes = AddCustomizedStringResourceParams.serializeBinary();
//             return _addon.AddCustomizedStringResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       },
//       /**
//       * Use the custom URL to replace the specified URL.
//       * If customizedUrl is NULL or is not NULL but with length zero(0), the return value is SDKERR_INVALID_PARAMETER.
// 	    * You must call the function first before calling InitSDK(), or no, it won't work.
//       * @method Resource_AddCustomizedURLResource
//       * @param {String} CustomizedURLType Specify the URL type. Defined in: {@link SDKCustomizedURLType}
//       * @param {String} strCustomizeURL Specify the custom URL.
//       * @return {Number} Defined in: {@link ZoomSDKError}
//       */
//       Resource_AddCustomizedURLResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let CustomizedURLType = clientOpts.CustomizedURLType;
//           let strCustomizeURL = clientOpts.strCustomizeURL;
//           try {
//             let AddCustomizedURLResourceParams = new messages.AddCustomizedURLResourceParams();
//             AddCustomizedURLResourceParams.setCustomizedurltype(CustomizedURLType);
//             AddCustomizedURLResourceParams.setStrcustomizedurl(strCustomizeURL);
//             let bytes = AddCustomizedURLResourceParams.serializeBinary();
//             return _addon.AddCustomizedURLResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       }
//     };
//   };
//   return {
//     getInstance: function (opts) {
//       if (!instance) {
//         instance = init(opts);
//       }
//       return instance;
//     }
//   };
// })();

// module.exports = {
//   ZoomCustomizedResource: ZoomCustomizedResource
// }


// *********************************************************************


// const { ZoomSDKError } = require('./settings.js');
// const messages = require('./electron_sdk_pb.js');

// var ZoomCustomizedResource = (function () {
//   var instance;

//   function init(opts) {
//     var clientOpts = opts || {};

//     var _addon = clientOpts.addon || {};

//     return {
//       Resource_AddCustomizedPictureResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let strPNGID = clientOpts.strPNGID;
//           let strPNGPath = clientOpts.strPNGPath;
//           try {
//             let AddCustomizedPictureResourceParams = new messages.AddCustomizedPictureResourceParams();
//             AddCustomizedPictureResourceParams.setStrpngid(strPNGID);
//             AddCustomizedPictureResourceParams.setStrpngpath(strPNGPath);
//             let bytes = AddCustomizedPictureResourceParams.serializeBinary();
//             return _addon.AddCustomizedPictureResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       },

//       Resource_AddCustomizedStringResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let CustomizedStringType = clientOpts.CustomizedStringType;
//           let strCustomizedString = clientOpts.strCustomizedString;
//           try {
//             let AddCustomizedStringResourceParams = new messages.AddCustomizedStringResourceParams();
//             AddCustomizedStringResourceParams.setCustomizedstringtype(CustomizedStringType);
//             AddCustomizedStringResourceParams.setStrcustomizedstring(strCustomizedString);
//             let bytes = AddCustomizedStringResourceParams.serializeBinary();
//             return _addon.AddCustomizedStringResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       },

//       Resource_AddCustomizedURLResource: function (opts) {
//         if (_addon) {
//           let clientOpts = opts || {};
//           let CustomizedURLType = clientOpts.CustomizedURLType;
//           let strCustomizeURL = clientOpts.strCustomizeURL;
//           try {
//             let AddCustomizedURLResourceParams = new messages.AddCustomizedURLResourceParams();
//             AddCustomizedURLResourceParams.setCustomizedurltype(CustomizedURLType);
//             AddCustomizedURLResourceParams.setStrcustomizedurl(strCustomizeURL);
//             let bytes = AddCustomizedURLResourceParams.serializeBinary();
//             return _addon.AddCustomizedURLResource(bytes);
//           } catch (error) {
//             return ZoomSDKError.SDKERR_INVALID_PARAMETER;
//           }
//         }
//         return ZoomSDKError.SDKERR_UNINITIALIZE;
//       }

//     };
//   }

//   return {
//     getInstance: function (opts) {
//       if (!instance) {
//         instance = init(opts);
//       }
//       return instance;
//     }
//   };
// })();

// const addon = {
//   GetCustomizedResourceObj: function () {
//     // Implement the logic to get the customized resource object
//     // Replace this with your own implementation
//     console.log('Getting customized resource object');
//     // Return the customized resource object or perform any necessary operations
//     return {}; // Replace with your implementation
//   },
//   AddCustomizedPictureResource: function (bytes) {
//     // Implement the logic to add a customized picture resource
//     // Replace this with your own implementation
//     console.log('Adding customized picture resource:', bytes);
//     // Return a success/error code based on the implementation
//     return 0; // Replace with your desired success/error code
//   },
//   AddCustomizedStringResource: function (bytes) {
//     // Implement the logic to add a customized string resource
//     // Replace this with your own implementation
//     console.log('Adding customized string resource:', bytes);
//     // Return a success/error code based on the implementation
//     return 0; // Replace with your desired success/error code
//   },
//   AddCustomizedURLResource: function (bytes) {
//     // Implement the logic to add a customized URL resource
//     // Replace this with your own implementation
//     console.log('Adding customized URL resource:', bytes);
//     // Return a success/error code based on the implementation
//     return 0; // Replace with your desired success/error code
//   }
// };

// const customizedResource = ZoomCustomizedResource.getInstance({ addon });

// // Now you can use the methods of `customizedResource`
// customizedResource.Resource_AddCustomizedPictureResource({
//   strPNGID: '123',
//   strPNGPath: '/path/to/custom.png'
// });

// module.exports = {
//   ZoomCustomizedResource: ZoomCustomizedResource
// };




// *********************************************************** changes here


const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');
// const { ZoomSDK } = require('./zoomsdk.js');
var ZoomCustomizedResource = (function () {
  var instance;

  function init(opts) {
    var clientOpts = opts || {};

    var _addon = clientOpts.addon || {};

    return {
      Resource_AddCustomizedPictureResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let strPNGID = clientOpts.strPNGID;
          let strPNGPath = clientOpts.strPNGPath;
          try {
            let AddCustomizedPictureResourceParams = new messages.AddCustomizedPictureResourceParams();
            AddCustomizedPictureResourceParams.setStrpngid(strPNGID);
            AddCustomizedPictureResourceParams.setStrpngpath(strPNGPath);
            let bytes = AddCustomizedPictureResourceParams.serializeBinary();
            return _addon.AddCustomizedPictureResource(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },

      Resource_AddCustomizedStringResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let CustomizedStringType = clientOpts.CustomizedStringType;
          let strCustomizedString = clientOpts.strCustomizedString;
          try {
            let AddCustomizedStringResourceParams = new messages.AddCustomizedStringResourceParams();
            AddCustomizedStringResourceParams.setCustomizedstringtype(CustomizedStringType);
            AddCustomizedStringResourceParams.setStrcustomizedstring(strCustomizedString);
            let bytes = AddCustomizedStringResourceParams.serializeBinary();
            return _addon.AddCustomizedStringResource(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },

      Resource_AddCustomizedURLResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let CustomizedURLType = clientOpts.CustomizedURLType;
          let strCustomizeURL = clientOpts.strCustomizeURL;
          try {
            let AddCustomizedURLResourceParams = new messages.AddCustomizedURLResourceParams();
            AddCustomizedURLResourceParams.setCustomizedurltype(CustomizedURLType);
            AddCustomizedURLResourceParams.setStrcustomizedurl(strCustomizeURL);
            let bytes = AddCustomizedURLResourceParams.serializeBinary();
            return _addon.AddCustomizedURLResource(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },

      // InitSDK: function (opts) {
      //   console.log("going1")
      //   if (_addon) {
      //     let clientOpts = opts || {};
      //     let apiKey = clientOpts.apiKey;
      //     let apiSecret = clientOpts.apiSecret;
      //     try {
      //       console.log("going2")
      //       // Initialize the Zoom SDK with the provided API key and secret
      //       _addon.Initialize(apiKey, apiSecret);
      //       console.log("yes")
      //       return ZoomSDKError.SDKERR_SUCCESS;
      //     } catch (error) {
      //       console.error('Error initializing Zoom SDK:', error);
      //       return ZoomSDKError.SDKERR_INVALID_PARAMETER;
      //     }
      //   }
      //   return ZoomSDKError.SDKERR_UNINITIALIZE;
      // }
    };
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

const addon = {
  GetCustomizedResourceObj: function () {
    // Implement the logic to get the customized resource object
    // Replace this with your own implementation
    console.log('Getting customized resource object');
    // Return the customized resource object or perform any necessary operations
    return {}; // Replace with your implementation
  },
  AddCustomizedPictureResource: function (bytes) {
    // Implement the logic to add a customized picture resource
    // Replace this with your own implementation
    console.log('Adding customized picture resource:', bytes);
    // Return a success/error code based on the implementation
    return 0; // Replace with your desired success/error code
  },
  AddCustomizedStringResource: function (bytes) {
    // Implement the logic to add a customized string resource
    // Replace this with your own implementation
    console.log('Adding customized string resource:', bytes);
    // Return a success/error code based on the implementation
    return 0; // Replace with your desired success/error code
  },
  AddCustomizedURLResource: function (bytes) {
    // Implement the logic to add a customized URL resource
    // Replace this with your own implementation
    console.log('Adding customized URL resource:', bytes);
    // Return a success/error code based on the implementation
    return 0; // Replace with your desired success/error code
  },

  // Initialize: function (apiKey, apiSecret) {
  //   console.log("hello")
  //   // const ZoomWebSDK = require('zoomus-jssdk'); // Import the Zoom Web SDK

  //   // console.log(ZoomWebSDK)

  //   console.log('Initializing Zoom SDK:', apiKey, apiSecret);

  //   // **************************************************
  //   // ZoomWebSDK.setZoomJSLib('https://source.zoom.us/zoom-meeting-1.7.2.min.js', '/av');
  //   // ZoomWebSDK.init({
  //   //   apiKey: apiKey,
  //   //   apiSecret: apiSecret,
  //   //   success: function () {
  //   //     console.log('Zoom SDK initialized successfully!');
  //   //   },
  //   //   error: function (res) {
  //   //     console.error('Error initializing Zoom SDK:', res);
  //   //   }
  //   // });

  //   // this.isSDKInitialized = true;

  //   // ***********************************

  //   const zoomSdkInstance = ZoomSDK.getInstance({
  //     path: './zoomsdk.js', // Replace this with the actual absolute path to the zoomsdk.node file
  //     domain: 'https://www.zoom.us', // Replace with your Zoom API domain
  //     apiKey: apiKey,
  //     apiSecret: apiSecret,
  //     // Add other required and optional parameters here
  //   });


  //   if (zoomSdkInstance.isSDKInitialized()) {
  //     console.log('Zoom SDK is already initialized.');
  //     return;
  //   }

  //   const initResult = zoomSdkInstance.InitSDK();
  //   if (initResult === ZoomSDKError.SDKERR_SUCCESS) {
  //     console.log('Zoom SDK initialized successfully!');
  //   } else {
  //     console.error('Error initializing Zoom SDK. Error code:', initResult);
  //   }


  // },
  // isSDKInitialized: false


}

const customizedResource = ZoomCustomizedResource.getInstance({ addon });

// addon.Initialize('O0SpTqc4RwCfi8s3RHt6Fw', 'OApN5zvzQAjmHng7j0U3INzf3x1QrExI');
console.log(customizedResource)
// Initialize the Zoom SDK
// customizedResource.InitSDK({
//   apiKey: 'O0SpTqc4RwCfi8s3RHt6Fw',
//   apiSecret: 'OApN5zvzQAjmHng7j0U3INzf3x1QrExI'
// });

// Now you can use the methods of `customizedResource`
customizedResource.Resource_AddCustomizedPictureResource({
  strPNGID: 'flower1',
  strPNGPath: 'C:/Users/Ananya Doshi/Downloads/flower.png'
});

module.exports = {
  ZoomCustomizedResource: ZoomCustomizedResource
};








