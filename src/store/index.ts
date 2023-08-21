import { createStore } from 'vuex'


let payload={
  meetingNumber:82175719416,
  role:0,
  sdkKey:'O0SpTqc4RwCfi8s3RHt6Fw',
  sdkSecret:'OApN5zvzQAjmHng7j0U3INzf3x1QrExI',
  passWord:'9aEYCV',
  userName:'Testing',
  userEmail:'',
  leaveUrl:'https://localhost:8081'
}

export default createStore({
  state: {
    zoomAuth: {},
    zoomMeeting: {}
  },
  mutations: {
    setZoomAuth (state, zoomAuth) {
      state.zoomAuth = zoomAuth
    },
    setZoomMeeting (state, zoomMeeting) {
      state.zoomMeeting = zoomMeeting
    }
  },
  actions: {
  },
  modules: {
  }
})
