using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraControls : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
        if (Input.GetKey(KeyCode.W))
        {
            transform.position +=transform.forward;
            Debug.Log(transform.position.ToString());
        }
        if (Input.GetKey(KeyCode.S))
        {
            transform.position -= transform.forward;
        }
        if (Input.GetKey(KeyCode.A))
        {
            transform.position -= transform.right;
        }
        if (Input.GetKey(KeyCode.D))
        {
            transform.position += transform.right;
        }
    }
}
