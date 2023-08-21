<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="isAnnotaionDisable">IsAnnotaionDisable</el-button>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-input v-model.trim="left" placeholder="input left" />
      <el-input v-model.trim="top" placeholder="input top" />
      <el-button type="primary" round plain @click="startAnnotation">StartAnnotation</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="stopAnnotation">StopAnnotation</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-select v-model="toolType" placeholder="Select">
        <el-option v-for="(item, key) in ZoomAnnotationToolType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="setTool">SetTool</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-select v-model="clearType" placeholder="Select">
        <el-option v-for="(item, key) in ZoomAnnotationClearType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="clear">Clear</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-input v-model.trim="color" placeholder="input color" />
      <el-button type="primary" round plain @click="setColor">SetColor</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-input-number v-model="lineWidth" :min="0" />
      <el-button type="primary" round plain @click="setLineWidth">SetLineWidth</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="undo">Undo</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="viewtype" placeholder="Select">
        <el-option v-for="(item, key) in SDKViewType" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="redo">Redo</el-button>
    </div>
    <el-button type="primary" round plain @click="isAnnotationLegalNoticeAvailable">IsAnnotationLegalNoticeAvailable</el-button>
    <el-button type="primary" round plain @click="getAnnotationLegalNoticesPrompt">GetAnnotationLegalNoticesPrompt</el-button>
    <el-button type="primary" round plain @click="getAnnotationLegalNoticesExplained">GetAnnotationLegalNoticesExplained</el-button>
  </div>
  <div class="result">Result: {{result}}</div>
</template>

<script setup lang="ts">
import { ref } from 'vue'
import { SDKViewType, ZoomAnnotationToolType, ZoomAnnotationClearType } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()

const zoomMeetingAnnotation = remote.app.zoomSdkModule.Meeting.GetAnnotationCtrl()
const viewtype = ref(0)
const left = ref()
const top = ref()
const toolType = ref(0)
const clearType = ref(0)
const color = ref()
const lineWidth = ref(1)

const isAnnotaionDisable = () => {
  let ret = zoomMeetingAnnotation.Annotaion_IsAnnotaionDisable()
  result.value = getSDKResult('Annotaion_IsAnnotaionDisable', ret)
}

const startAnnotation = () => {
  let param = {
    viewtype: viewtype.value,
    left: left.value,
    top: top.value
  }
  let ret = zoomMeetingAnnotation.Annotaion_StartAnnotation(param)
  result.value = getSDKResult('Annotaion_StartAnnotation', ret, param)
}

const stopAnnotation = () => {
  let param = {
    viewtype: viewtype.value,
  }
  let ret = zoomMeetingAnnotation.Annotaion_StopAnnotation(param)
  result.value = getSDKResult('Annotaion_StopAnnotation', ret, param)
}

const setTool = () => {
  let param = {
    viewtype: viewtype.value,
    toolType: toolType.value
  }
  let ret = zoomMeetingAnnotation.Annotaion_SetTool(param)
  result.value = getSDKResult('Annotaion_SetTool', ret, param)
}

const clear = () => {
  let param = {
    viewtype: viewtype.value,
    clearType: clearType.value
  }
  let ret = zoomMeetingAnnotation.Annotaion_Clear(param)
  result.value = getSDKResult('Annotaion_Clear', ret, param)
}

const setColor = () => {
  let param = {
    viewtype: viewtype.value,
    color: color.value
  }
  let ret = zoomMeetingAnnotation.Annotaion_SetColor(param)
  result.value = getSDKResult('Annotaion_SetColor', ret, param)
}

const setLineWidth = () => {
  let param = {
    viewtype: viewtype.value,
    lineWidth: lineWidth.value
  }
  let ret = zoomMeetingAnnotation.Annotaion_SetLineWidth(param)
  result.value = getSDKResult('Annotaion_SetLineWidth', ret, param)
}

const undo = () => {
  let param = {
    viewtype: viewtype.value,
  }
  let ret = zoomMeetingAnnotation.Annotaion_Undo(param)
  result.value = getSDKResult('Annotaion_Undo', ret, param)
}

const redo = () => {
  let param = {
    viewtype: viewtype.value,
  }
  let ret = zoomMeetingAnnotation.Annotaion_Redo(param)
  result.value = getSDKResult('Annotaion_Redo', ret, param)
}

const isAnnotationLegalNoticeAvailable = () => {
  let ret = zoomMeetingAnnotation.Annotaion_IsAnnotationLegalNoticeAvailable();
  result.value = getSDKResult('Annotaion_IsAnnotationLegalNoticeAvailable', ret)
}

const getAnnotationLegalNoticesPrompt = () => {
  let ret = zoomMeetingAnnotation.Annotaion_GetAnnotationLegalNoticesPrompt();
  result.value = getSDKResult('Annotaion_GetAnnotationLegalNoticesPrompt', ret)
}

const getAnnotationLegalNoticesExplained = () => {
  let ret = zoomMeetingAnnotation.Annotaion_GetAnnotationLegalNoticesExplained();
  result.value = getSDKResult('Annotaion_GetAnnotationLegalNoticesExplained', ret)
}
</script>