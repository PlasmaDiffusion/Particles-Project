using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ParticleCreation : MonoBehaviour {

    public GameObject fireworkPrefab;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        transform.position = Input.mousePosition;

        if (Input.GetMouseButtonUp(0))
        {
            Instantiate(fireworkPrefab, transform);
            
        }
	}
}
