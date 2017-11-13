using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ParticleSwitcher : MonoBehaviour {

    public GameObject defaultReference;
    public GameObject fireworkReference;
    public GameObject fountainReference;

    public GameObject currentSpawner;

    private int currentSystem;

    // Use this for initialization
    void Start () {

        currentSystem = 0;   
	}
	
	// Update is called once per frame
	void Update () {

        //Press space to stop the current particle system.
        if (Input.GetKeyUp(KeyCode.Space))
        {

        
         if (currentSpawner)
         {

            Destroy(currentSpawner);
            currentSystem++;
            if (currentSystem > 2) currentSystem = 0;


         }
         else //Press space again to change to the next one
         {

            switch (currentSystem)
            {
                case 0:

                    currentSpawner = Instantiate(defaultReference);

                    break;
                case 1:

                    currentSpawner = Instantiate(fireworkReference);

                    break;
                case 2:

                    currentSpawner = Instantiate(fountainReference);

                    break;


            }

         }

        }



    }
}
