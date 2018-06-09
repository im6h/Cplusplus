import React,{Component} from 'react';
import {View, StyleSheet,Text} from 'react-native';
class FirstApp extends Component {
  render() {
    return (<Text>Hello {this.props.name}</Text>);
  }
}
export default class LotsOfApp extends Component {
  render() {
    return (<View style={{
        alignItems: 'center'
      }}>
      <FirstApp name='Vu'></FirstApp>
      <FirstApp name='Vu'></FirstApp>
      <FirstApp name='Hai'></FirstApp>
    </View>);
  }
}
