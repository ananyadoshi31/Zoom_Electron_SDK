import { RouteRecordRaw } from 'vue-router'

const meeting_routes: Array<RouteRecordRaw> = [
  { 
    path: '/meeting',
    name: 'Meeting_Index',
    component: () => import(/* webpackChunkName: "meeting_index" */ '../views/meeting/Index.vue'),
    children: [
      {
        path: 'meeting',
        name: 'Meeting',
        component: () => import(/* webpackChunkName: "meeting_meeting" */ '../views/meeting/Meeting.vue'),
      },
      {
        path: 'info',
        name: 'Meeting Info',
        component: () => import(/* webpackChunkName: "meeting_info" */ '../views/meeting/Info.vue'),
      },
      {
        path: 'participants',
        name: 'Meeting Participants',
        component: () => import(/* webpackChunkName: "meeting_participants" */ '../views/meeting/Participants.vue'),
      },
      {
        path: 'audio',
        name: 'Meeting Audio',
        component: () => import(/* webpackChunkName: "meeting_audio" */ '../views/meeting/Audio.vue'),
      },
      {
        path: 'video',
        name: 'Meeting Video',
        component: () => import(/* webpackChunkName: "meeting_video" */ '../views/meeting/Video.vue'),
      },
      {
        path: 'share',
        name: 'Meeting Share',
        component: () => import(/* webpackChunkName: "meeting_share" */ '../views/meeting/Share.vue'),
      },
      {
        path: 'config',
        name: 'Meeting Config',
        component: () => import(/* webpackChunkName: "meeting_config" */ '../views/meeting/Config.vue'),
      },
      {
        path: 'annotation',
        name: 'Meeting Annotation',
        component: () => import(/* webpackChunkName: "meeting_annotation" */ '../views/meeting/Annotation.vue'),
      },
      {
        path: 'directshare',
        name: 'Meeting DirectShare',
        component: () => import(/* webpackChunkName: "meeting_directshare" */ '../views/meeting/DirectShare.vue'),
      },
      {
        path: 'recording',
        name: 'Meeting Recording',
        component: () => import(/* webpackChunkName: "meeting_recording" */ '../views/meeting/Recording.vue'),
      },
      {
        path: 'h323',
        name: 'Meeting H323',
        component: () => import(/* webpackChunkName: "meeting_h323" */ '../views/meeting/H323.vue'),
      },
      {
        path: 'ui',
        name: 'Meeting UI',
        component: () => import(/* webpackChunkName: "meeting_ui" */ '../views/meeting/UI.vue'),
      },
      {
        path: 'aan',
        name: 'Meeting AAN',
        component: () => import(/* webpackChunkName: "meeting_aan" */ '../views/meeting/AAN.vue'),
      },
      {
        path: 'rawarchiving',
        name: 'Meeting RawArchivingCtrl',
        component: () => import(/* webpackChunkName: "meeting_rawarchivingctrl" */ '../views/meeting/RawArchivingCtrl.vue'),
      },
      {
        path: 'livestream',
        name: 'Meeting LiveStream',
        component: () => import(/* webpackChunkName: "meeting_livestream" */ '../views/meeting/LiveStream.vue'),
      },
      {
        path: 'reqrawlive',
        name: 'Meeting RequestRawLiveStreamPrivilege',
        component: () => import(/* webpackChunkName: "meeting_requestrawlivestreamprivilege" */ '../views/meeting/RequestRawLiveStreamPrivilege.vue'),
      },
      {
        path: 'realname',
        name: 'RealName',
        component: () => import(/* webpackChunkName: "meeting_realname" */ '../views/meeting/RealName.vue'),
      },
      {
        path: 'auth',
        name: 'Auth',
        component: () => import(/* webpackChunkName: "auth" */ '../views/meeting/Auth.vue'),
      }
    ],
  },
  {
    path: '/rawdata',
    name: 'Rawdata',
    component: () => import(/* webpackChunkName: "meeting_rawdata" */ '../views/meeting/Rawdata.vue'),
  }
]

export default meeting_routes
