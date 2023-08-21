// import { ElMessage } from 'element-plus'
// import { ZoomSDKError } from '../../../lib/settings.js'

// function getResultDesc(api: string, value: any, toast = false, compare = (a: number, b: number) => a == b) {
//   let result = Object.keys(ZoomSDKError).find(k => compare(ZoomSDKError[k], value))
//   let tip = `${api}: ${result}`
//   if (result == 'SDKERR_SUCCESS') {
//     console.log(tip)
//   } else if (toast && result) {
//     toastResult(tip)
//   }
//   return result
// }

// function toastResult(tip: string) {
//   console.warn(tip)
//   ElMessage.warning(tip)
// }

// function getSDKResult(api: string, ret: any, param?: any, getDescFromEnum = true) {
//   let tip: string | undefined = JSON.stringify(ret)
//   if (typeof ret == 'number' && getDescFromEnum) {
//     tip = getResultDesc(api, ret)
//   }
//   if (param) {
//     return `${api} - ${JSON.stringify(param)} - ${tip}`
//   }
//   return `${api} - ${tip}`
// }

// export {
//   getResultDesc,
//   getSDKResult,
//   toastResult
// }


// ******************************************************************************


import { ElMessage } from 'element-plus'
import { ZoomSDKError } from '../../../lib/settings.js'

function getResultDesc(api: string, value: any, toast = false, compare = (a: number, b: number) => a == b) {
  let result = Object.keys(ZoomSDKError).find(k => compare(ZoomSDKError[k], value))
  let tip = `${api}: ${result}`
  if (result == 'SDKERR_SUCCESS') {
    console.log(tip)
  } else if (toast && result) {
    toastResult(tip)
  }
  return result
}

function toastResult(tip: string) {
  console.warn(tip)
  ElMessage.warning(tip)
}

function getSDKResult(api: string, ret: any, param?: any, getDescFromEnum = true) {
  let tip: string | undefined = JSON.stringify(ret)
  if (typeof ret == 'number' && getDescFromEnum) {
    tip = getResultDesc(api, ret)
  }
  if (param) {
    return `${api} - ${JSON.stringify(param)} - ${tip}`
  }
  return `${api} - ${tip}`
}

export {
  getResultDesc,
  getSDKResult,
  toastResult
}